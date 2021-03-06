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
struct nfp_net_tx_ring {int dummy; } ;

/* Variables and functions */
 scalar_t__ MAX_SKB_FRAGS ; 
 int nfp_net_tx_full (struct nfp_net_tx_ring*,scalar_t__) ; 

__attribute__((used)) static int nfp_net_tx_ring_should_stop(struct nfp_net_tx_ring *tx_ring)
{
	return nfp_net_tx_full(tx_ring, MAX_SKB_FRAGS + 1);
}