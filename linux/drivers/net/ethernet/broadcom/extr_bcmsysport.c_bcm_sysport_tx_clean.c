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
struct bcm_sysport_tx_ring {int /*<<< orphan*/  lock; } ;
struct bcm_sysport_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __bcm_sysport_tx_reclaim (struct bcm_sysport_priv*,struct bcm_sysport_tx_ring*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void bcm_sysport_tx_clean(struct bcm_sysport_priv *priv,
				 struct bcm_sysport_tx_ring *ring)
{
	unsigned long flags;

	spin_lock_irqsave(&ring->lock, flags);
	__bcm_sysport_tx_reclaim(priv, ring);
	spin_unlock_irqrestore(&ring->lock, flags);
}