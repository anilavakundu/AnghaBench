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
struct TYPE_2__ {int /*<<< orphan*/  prtad; } ;
struct cphy {TYPE_1__ mdio; } ;

/* Variables and functions */
 int /*<<< orphan*/  MDIO_CTRL1 ; 
 int /*<<< orphan*/  MDIO_CTRL1_LPOWER ; 
 int /*<<< orphan*/  MDIO_MMD_PMAPMD ; 
 int /*<<< orphan*/  MDIO_PMA_TXDIS ; 
 int mdio_set_flag (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int t3_mdio_write (struct cphy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int ael1002_power_down(struct cphy *phy, int enable)
{
	int err;

	err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, MDIO_PMA_TXDIS, !!enable);
	if (!err)
		err = mdio_set_flag(&phy->mdio, phy->mdio.prtad,
				    MDIO_MMD_PMAPMD, MDIO_CTRL1,
				    MDIO_CTRL1_LPOWER, enable);
	return err;
}