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
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_4__ {scalar_t__ writes_counter; TYPE_1__* ops; } ;
struct b43_wldev {TYPE_2__ phy; int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* radio_write ) (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 scalar_t__ B43_MAX_WRITES_IN_ROW ; 
 int /*<<< orphan*/  B43_MMIO_MACCTL ; 
 int /*<<< orphan*/  assert_mac_suspended (struct b43_wldev*) ; 
 scalar_t__ b43_bus_host_is_pci (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_read32 (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void b43_radio_write(struct b43_wldev *dev, u16 reg, u16 value)
{
	assert_mac_suspended(dev);
	if (b43_bus_host_is_pci(dev->dev) &&
	    ++dev->phy.writes_counter > B43_MAX_WRITES_IN_ROW) {
		b43_read32(dev, B43_MMIO_MACCTL);
		dev->phy.writes_counter = 1;
	}
	dev->phy.ops->radio_write(dev, reg, value);
}