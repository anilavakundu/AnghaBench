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

__attribute__((used)) static void
null_addba_response_timeout(struct ieee80211_node *ni,
    struct ieee80211_tx_ampdu *tap)
{
}