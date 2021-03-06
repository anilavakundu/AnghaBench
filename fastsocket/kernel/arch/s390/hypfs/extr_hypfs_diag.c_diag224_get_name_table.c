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
 int /*<<< orphan*/  EBCASC (int*,int) ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int GFP_DMA ; 
 int GFP_KERNEL ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 scalar_t__ diag224 (int*) ; 
 int* diag224_cpu_names ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int diag224_get_name_table(void)
{
	/* memory must be below 2GB */
	diag224_cpu_names = kmalloc(PAGE_SIZE, GFP_KERNEL | GFP_DMA);
	if (!diag224_cpu_names)
		return -ENOMEM;
	if (diag224(diag224_cpu_names)) {
		kfree(diag224_cpu_names);
		return -EOPNOTSUPP;
	}
	EBCASC(diag224_cpu_names + 16, (*diag224_cpu_names + 1) * 16);
	return 0;
}