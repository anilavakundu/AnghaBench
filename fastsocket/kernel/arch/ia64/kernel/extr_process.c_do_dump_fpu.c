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
struct unw_frame_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  do_dump_task_fpu (int /*<<< orphan*/ ,struct unw_frame_info*,void*) ; 

void
do_dump_fpu (struct unw_frame_info *info, void *arg)
{
	do_dump_task_fpu(current, info, arg);
}