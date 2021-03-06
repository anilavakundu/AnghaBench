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
typedef  int /*<<< orphan*/  u8 ;
struct pcie_service_card {scalar_t__ pci_mmap1; } ;
struct mwifiex_adapter {struct pcie_service_card* card; } ;

/* Variables and functions */
 int /*<<< orphan*/  ioread8 (scalar_t__) ; 

__attribute__((used)) static int mwifiex_read_reg_byte(struct mwifiex_adapter *adapter,
				 int reg, u8 *data)
{
	struct pcie_service_card *card = adapter->card;

	*data = ioread8(card->pci_mmap1 + reg);

	return 0;
}