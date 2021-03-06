#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ reseed_count; scalar_t__ fail; } ;
typedef  TYPE_1__ HOOK_CTX ;

/* Variables and functions */

__attribute__((used)) static void reset_hook_ctx(HOOK_CTX *ctx)
{
    ctx->fail = 0;
    ctx->reseed_count = 0;
}