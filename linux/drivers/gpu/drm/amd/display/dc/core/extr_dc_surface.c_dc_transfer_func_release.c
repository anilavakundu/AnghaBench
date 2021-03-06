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
struct dc_transfer_func {int /*<<< orphan*/  refcount; } ;

/* Variables and functions */
 int /*<<< orphan*/  dc_transfer_func_free ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void dc_transfer_func_release(struct dc_transfer_func *tf)
{
	kref_put(&tf->refcount, dc_transfer_func_free);
}