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
typedef  scalar_t__ u32 ;
struct net_device {int dummy; } ;
struct jme_adapter {int /*<<< orphan*/  rxmcs_lock; int /*<<< orphan*/  reg_rxmcs; } ;

/* Variables and functions */
 int /*<<< orphan*/  JME_RXMCS ; 
 int /*<<< orphan*/  RXMCS_CHECKSUM ; 
 int /*<<< orphan*/  jwrite32 (struct jme_adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct jme_adapter* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
jme_set_rx_csum(struct net_device *netdev, u32 on)
{
	struct jme_adapter *jme = netdev_priv(netdev);

	spin_lock_bh(&jme->rxmcs_lock);
	if (on)
		jme->reg_rxmcs |= RXMCS_CHECKSUM;
	else
		jme->reg_rxmcs &= ~RXMCS_CHECKSUM;
	jwrite32(jme, JME_RXMCS, jme->reg_rxmcs);
	spin_unlock_bh(&jme->rxmcs_lock);

	return 0;
}