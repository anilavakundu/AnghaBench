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
struct wireless_dev {struct wiphy* wiphy; } ;
struct wiphy {int dummy; } ;
struct net_device {struct wireless_dev* ieee80211_ptr; } ;
struct cfg80211_registered_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  NL80211_CMD_UNPROT_DISASSOCIATE ; 
 int /*<<< orphan*/  nl80211_send_mlme_event (struct cfg80211_registered_device*,struct net_device*,int /*<<< orphan*/  const*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_cfg80211_send_unprot_disassoc (struct net_device*) ; 
 struct cfg80211_registered_device* wiphy_to_dev (struct wiphy*) ; 

void cfg80211_send_unprot_disassoc(struct net_device *dev, const u8 *buf,
				   size_t len)
{
	struct wireless_dev *wdev = dev->ieee80211_ptr;
	struct wiphy *wiphy = wdev->wiphy;
	struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);

	trace_cfg80211_send_unprot_disassoc(dev);
	nl80211_send_mlme_event(rdev, dev, buf, len,
				NL80211_CMD_UNPROT_DISASSOCIATE, GFP_ATOMIC);
}