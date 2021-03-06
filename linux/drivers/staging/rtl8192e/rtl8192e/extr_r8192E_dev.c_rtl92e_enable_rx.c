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
struct r8192_priv {int /*<<< orphan*/ * rx_ring_dma; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RDQDA ; 
 size_t RX_MPDU_QUEUE ; 
 int /*<<< orphan*/  rtl92e_writel (struct net_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ rtllib_priv (struct net_device*) ; 

void rtl92e_enable_rx(struct net_device *dev)
{
	struct r8192_priv *priv = (struct r8192_priv *)rtllib_priv(dev);

	rtl92e_writel(dev, RDQDA, priv->rx_ring_dma[RX_MPDU_QUEUE]);
}