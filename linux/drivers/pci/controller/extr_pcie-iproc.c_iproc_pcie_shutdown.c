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
struct iproc_pcie {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  iproc_pcie_perst_ctrl (struct iproc_pcie*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 

int iproc_pcie_shutdown(struct iproc_pcie *pcie)
{
	iproc_pcie_perst_ctrl(pcie, true);
	msleep(500);

	return 0;
}