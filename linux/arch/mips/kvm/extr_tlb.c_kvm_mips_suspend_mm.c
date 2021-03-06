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
struct TYPE_2__ {int /*<<< orphan*/ * active_mm; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpumask_clear_cpu (int,int /*<<< orphan*/ ) ; 
 TYPE_1__* current ; 
 int /*<<< orphan*/  init_mm ; 
 int /*<<< orphan*/  mm_cpumask (int /*<<< orphan*/ *) ; 

void kvm_mips_suspend_mm(int cpu)
{
	cpumask_clear_cpu(cpu, mm_cpumask(current->active_mm));
	current->active_mm = &init_mm;
}