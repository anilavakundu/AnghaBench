#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  const u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_9__ {int /*<<< orphan*/  const* addr; } ;
struct TYPE_10__ {TYPE_3__ virt; } ;
struct TYPE_7__ {int /*<<< orphan*/  const* addr; } ;
struct TYPE_8__ {TYPE_1__ virt; } ;
struct skcipher_walk {int total; int nbytes; TYPE_4__ src; TYPE_2__ dst; } ;
struct TYPE_11__ {int /*<<< orphan*/ * key_enc; } ;
struct gcm_aes_ctx {int /*<<< orphan*/  ghash_key; TYPE_5__ aes_key; } ;
struct crypto_aead {int dummy; } ;
struct aead_request {scalar_t__ cryptlen; scalar_t__ assoclen; int /*<<< orphan*/  src; int /*<<< orphan*/  const* iv; } ;

/* Variables and functions */
 int AES_BLOCK_SIZE ; 
 int EBADMSG ; 
 int GCM_IV_SIZE ; 
 int GHASH_BLOCK_SIZE ; 
 int /*<<< orphan*/  aes_encrypt (TYPE_5__*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 unsigned int crypto_aead_authsize (struct crypto_aead*) ; 
 struct gcm_aes_ctx* crypto_aead_ctx (struct crypto_aead*) ; 
 struct crypto_aead* crypto_aead_reqtfm (struct aead_request*) ; 
 int /*<<< orphan*/  crypto_inc (int /*<<< orphan*/  const*,int) ; 
 scalar_t__ crypto_memneq (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,unsigned int) ; 
 scalar_t__ crypto_simd_usable () ; 
 int /*<<< orphan*/  crypto_xor_cpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  gcm_calculate_auth_mac (struct aead_request*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gcm_final (struct aead_request*,struct gcm_aes_ctx*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,scalar_t__) ; 
 int /*<<< orphan*/  ghash_do_update (int,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kernel_neon_begin () ; 
 int /*<<< orphan*/  kernel_neon_end () ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int) ; 
 int num_rounds (TYPE_5__*) ; 
 int /*<<< orphan*/  pmull_gcm_decrypt (int,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  pmull_gcm_encrypt_block (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pmull_ghash_update_p64 ; 
 int /*<<< orphan*/  put_unaligned_be32 (int,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  scatterwalk_map_and_copy (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,scalar_t__,unsigned int,int /*<<< orphan*/ ) ; 
 int skcipher_walk_aead_decrypt (struct skcipher_walk*,struct aead_request*,int) ; 
 int skcipher_walk_done (struct skcipher_walk*,int) ; 

__attribute__((used)) static int gcm_decrypt(struct aead_request *req)
{
	struct crypto_aead *aead = crypto_aead_reqtfm(req);
	struct gcm_aes_ctx *ctx = crypto_aead_ctx(aead);
	unsigned int authsize = crypto_aead_authsize(aead);
	struct skcipher_walk walk;
	u8 iv[2 * AES_BLOCK_SIZE];
	u8 tag[AES_BLOCK_SIZE];
	u8 buf[2 * GHASH_BLOCK_SIZE];
	u64 dg[2] = {};
	int nrounds = num_rounds(&ctx->aes_key);
	int err;

	if (req->assoclen)
		gcm_calculate_auth_mac(req, dg);

	memcpy(iv, req->iv, GCM_IV_SIZE);
	put_unaligned_be32(1, iv + GCM_IV_SIZE);

	err = skcipher_walk_aead_decrypt(&walk, req, false);

	if (likely(crypto_simd_usable() && walk.total >= 2 * AES_BLOCK_SIZE)) {
		u32 const *rk = NULL;

		kernel_neon_begin();
		pmull_gcm_encrypt_block(tag, iv, ctx->aes_key.key_enc, nrounds);
		put_unaligned_be32(2, iv + GCM_IV_SIZE);

		do {
			int blocks = walk.nbytes / (2 * AES_BLOCK_SIZE) * 2;
			int rem = walk.total - blocks * AES_BLOCK_SIZE;

			if (rk)
				kernel_neon_begin();

			pmull_gcm_decrypt(blocks, dg, walk.dst.virt.addr,
					  walk.src.virt.addr, &ctx->ghash_key,
					  iv, rk, nrounds);

			/* check if this is the final iteration of the loop */
			if (rem < (2 * AES_BLOCK_SIZE)) {
				u8 *iv2 = iv + AES_BLOCK_SIZE;

				if (rem > AES_BLOCK_SIZE) {
					memcpy(iv2, iv, AES_BLOCK_SIZE);
					crypto_inc(iv2, AES_BLOCK_SIZE);
				}

				pmull_gcm_encrypt_block(iv, iv, NULL, nrounds);

				if (rem > AES_BLOCK_SIZE)
					pmull_gcm_encrypt_block(iv2, iv2, NULL,
								nrounds);
			}

			kernel_neon_end();

			err = skcipher_walk_done(&walk,
					walk.nbytes % (2 * AES_BLOCK_SIZE));

			rk = ctx->aes_key.key_enc;
		} while (walk.nbytes >= 2 * AES_BLOCK_SIZE);
	} else {
		aes_encrypt(&ctx->aes_key, tag, iv);
		put_unaligned_be32(2, iv + GCM_IV_SIZE);

		while (walk.nbytes >= (2 * AES_BLOCK_SIZE)) {
			int blocks = walk.nbytes / (2 * AES_BLOCK_SIZE) * 2;
			u8 *dst = walk.dst.virt.addr;
			u8 *src = walk.src.virt.addr;

			ghash_do_update(blocks, dg, walk.src.virt.addr,
					&ctx->ghash_key, NULL,
					pmull_ghash_update_p64);

			do {
				aes_encrypt(&ctx->aes_key, buf, iv);
				crypto_xor_cpy(dst, src, buf, AES_BLOCK_SIZE);
				crypto_inc(iv, AES_BLOCK_SIZE);

				dst += AES_BLOCK_SIZE;
				src += AES_BLOCK_SIZE;
			} while (--blocks > 0);

			err = skcipher_walk_done(&walk,
						 walk.nbytes % (2 * AES_BLOCK_SIZE));
		}
		if (walk.nbytes) {
			if (walk.nbytes > AES_BLOCK_SIZE) {
				u8 *iv2 = iv + AES_BLOCK_SIZE;

				memcpy(iv2, iv, AES_BLOCK_SIZE);
				crypto_inc(iv2, AES_BLOCK_SIZE);

				aes_encrypt(&ctx->aes_key, iv2, iv2);
			}
			aes_encrypt(&ctx->aes_key, iv, iv);
		}
	}

	/* handle the tail */
	if (walk.nbytes) {
		const u8 *src = walk.src.virt.addr;
		const u8 *head = NULL;
		unsigned int nbytes = walk.nbytes;

		if (walk.nbytes > GHASH_BLOCK_SIZE) {
			head = src;
			src += GHASH_BLOCK_SIZE;
			nbytes %= GHASH_BLOCK_SIZE;
		}

		memcpy(buf, src, nbytes);
		memset(buf + nbytes, 0, GHASH_BLOCK_SIZE - nbytes);
		ghash_do_update(!!nbytes, dg, buf, &ctx->ghash_key, head,
				pmull_ghash_update_p64);

		crypto_xor_cpy(walk.dst.virt.addr, walk.src.virt.addr, iv,
			       walk.nbytes);

		err = skcipher_walk_done(&walk, 0);
	}

	if (err)
		return err;

	gcm_final(req, ctx, dg, tag, req->cryptlen - authsize);

	/* compare calculated auth tag with the stored one */
	scatterwalk_map_and_copy(buf, req->src,
				 req->assoclen + req->cryptlen - authsize,
				 authsize, 0);

	if (crypto_memneq(tag, buf, authsize))
		return -EBADMSG;
	return 0;
}