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
struct TYPE_2__ {scalar_t__ x86_model; } ;

/* Variables and functions */
 scalar_t__ INTEL_FAM6_ATOM_AIRMONT ; 
 TYPE_1__ boot_cpu_data ; 

__attribute__((used)) static inline bool is_bsw(void)
{
#ifdef CONFIG_X86
	return ((boot_cpu_data.x86_model == INTEL_FAM6_ATOM_AIRMONT) ? 1 : 0);
#else
	return false;
#endif
}