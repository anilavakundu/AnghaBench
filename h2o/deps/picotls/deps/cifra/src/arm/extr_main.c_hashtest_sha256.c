#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  cf_sha256_context ;

/* Variables and functions */
 int CF_SHA256_HASHSZ ; 
 int /*<<< orphan*/  cf_sha256_digest_final (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cf_sha256_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cf_sha256_update (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void hashtest_sha256(void)
{
  uint8_t hash[CF_SHA256_HASHSZ];
  cf_sha256_context ctx;
  cf_sha256_init(&ctx);
  cf_sha256_update(&ctx, "", 0);
  cf_sha256_digest_final(&ctx, hash);
}