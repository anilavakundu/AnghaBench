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
typedef  int /*<<< orphan*/  u32 ;
struct iowait {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_hfi1_iowait_set (struct iowait*,int /*<<< orphan*/ ) ; 

void iowait_set_flag(struct iowait *wait, u32 flag)
{
	trace_hfi1_iowait_set(wait, flag);
	set_bit(flag, &wait->flags);
}