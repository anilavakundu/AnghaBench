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
struct sk_buff {int /*<<< orphan*/  dev; } ;
struct packet_type {int dummy; } ;
struct net_device {int dummy; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int NET_RX_DROP ; 
 int /*<<< orphan*/  NFPROTO_IPV6 ; 
 int NF_HOOK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct net*,int /*<<< orphan*/ *,struct sk_buff*,struct net_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NF_INET_PRE_ROUTING ; 
 struct net* dev_net (int /*<<< orphan*/ ) ; 
 struct sk_buff* ip6_rcv_core (struct sk_buff*,struct net_device*,struct net*) ; 
 int /*<<< orphan*/  ip6_rcv_finish ; 

int ipv6_rcv(struct sk_buff *skb, struct net_device *dev, struct packet_type *pt, struct net_device *orig_dev)
{
	struct net *net = dev_net(skb->dev);

	skb = ip6_rcv_core(skb, dev, net);
	if (skb == NULL)
		return NET_RX_DROP;
	return NF_HOOK(NFPROTO_IPV6, NF_INET_PRE_ROUTING,
		       net, NULL, skb, dev, NULL,
		       ip6_rcv_finish);
}