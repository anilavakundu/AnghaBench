#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  key_bits; int /*<<< orphan*/  ks; } ;
typedef  int /*<<< orphan*/  EVP_CIPHER_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  EVP_CIPHER_CTX_key_length (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RC2_set_key (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned char const*,int /*<<< orphan*/ ) ; 
 TYPE_1__* data (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int rc2_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
                        const unsigned char *iv, int enc)
{
    RC2_set_key(&data(ctx)->ks, EVP_CIPHER_CTX_key_length(ctx),
                key, data(ctx)->key_bits);
    return 1;
}