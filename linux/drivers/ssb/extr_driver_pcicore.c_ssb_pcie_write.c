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
struct ssb_pcicore {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pcicore_write32 (struct ssb_pcicore*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ssb_pcie_write(struct ssb_pcicore *pc, u32 address, u32 data)
{
	pcicore_write32(pc, 0x130, address);
	pcicore_write32(pc, 0x134, data);
}