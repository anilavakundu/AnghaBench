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

/* Variables and functions */
 scalar_t__ CLOCK_EVT_NOTIFY_RESUME ; 
 int /*<<< orphan*/  on_each_cpu (int /*<<< orphan*/ ,void*,int) ; 
 int /*<<< orphan*/  xen_vcpu_notify_restore ; 

void xen_arch_resume(void)
{
	on_each_cpu(xen_vcpu_notify_restore,
		    (void *)CLOCK_EVT_NOTIFY_RESUME, 1);
}