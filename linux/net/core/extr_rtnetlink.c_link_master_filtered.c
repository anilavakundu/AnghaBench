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
struct net_device {int ifindex; } ;

/* Variables and functions */
 struct net_device* netdev_master_upper_dev_get (struct net_device*) ; 

__attribute__((used)) static bool link_master_filtered(struct net_device *dev, int master_idx)
{
	struct net_device *master;

	if (!master_idx)
		return false;

	master = netdev_master_upper_dev_get(dev);
	if (!master || master->ifindex != master_idx)
		return true;

	return false;
}