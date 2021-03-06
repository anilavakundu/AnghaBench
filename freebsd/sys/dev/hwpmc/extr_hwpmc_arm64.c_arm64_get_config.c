#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct pmc {int dummy; } ;
struct TYPE_4__ {TYPE_1__* pc_arm64pmcs; } ;
struct TYPE_3__ {struct pmc* phw_pmc; } ;

/* Variables and functions */
 TYPE_2__** arm64_pcpu ; 

__attribute__((used)) static int
arm64_get_config(int cpu, int ri, struct pmc **ppm)
{

	*ppm = arm64_pcpu[cpu]->pc_arm64pmcs[ri].phw_pmc;

	return (0);
}