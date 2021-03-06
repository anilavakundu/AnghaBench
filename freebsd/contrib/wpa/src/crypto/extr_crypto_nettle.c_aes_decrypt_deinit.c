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
struct aes_ctx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bin_clear_free (struct aes_ctx*,int) ; 

void aes_decrypt_deinit(void *ctx)
{
	struct aes_ctx *actx = ctx;
	bin_clear_free(actx, sizeof(*actx));
}