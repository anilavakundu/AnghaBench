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
struct shash_desc {int dummy; } ;
struct rmd256_ctx {int /*<<< orphan*/  buffer; int /*<<< orphan*/ * state; scalar_t__ byte_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  RMD_H0 ; 
 int /*<<< orphan*/  RMD_H1 ; 
 int /*<<< orphan*/  RMD_H2 ; 
 int /*<<< orphan*/  RMD_H3 ; 
 int /*<<< orphan*/  RMD_H5 ; 
 int /*<<< orphan*/  RMD_H6 ; 
 int /*<<< orphan*/  RMD_H7 ; 
 int /*<<< orphan*/  RMD_H8 ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct rmd256_ctx* shash_desc_ctx (struct shash_desc*) ; 

__attribute__((used)) static int rmd256_init(struct shash_desc *desc)
{
	struct rmd256_ctx *rctx = shash_desc_ctx(desc);

	rctx->byte_count = 0;

	rctx->state[0] = RMD_H0;
	rctx->state[1] = RMD_H1;
	rctx->state[2] = RMD_H2;
	rctx->state[3] = RMD_H3;
	rctx->state[4] = RMD_H5;
	rctx->state[5] = RMD_H6;
	rctx->state[6] = RMD_H7;
	rctx->state[7] = RMD_H8;

	memset(rctx->buffer, 0, sizeof(rctx->buffer));

	return 0;
}