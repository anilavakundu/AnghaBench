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
struct vm_fault {int dummy; } ;
struct vm_area_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SPUFS_PS_MAP_SIZE ; 
 int spufs_ps_fault (struct vm_area_struct*,struct vm_fault*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
spufs_psmap_mmap_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
	return spufs_ps_fault(vma, vmf, 0x0000, SPUFS_PS_MAP_SIZE);
}