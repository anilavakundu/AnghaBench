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
struct ieee80211_tx_ampdu {int dummy; } ;
struct ieee80211_node {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int
otus_ampdu_enable(struct ieee80211_node *ni, struct ieee80211_tx_ampdu *tap)
{

	/* For now, no A-MPDU TX support in the driver */
	return (0);
}