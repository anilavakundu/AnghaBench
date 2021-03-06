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
typedef  scalar_t__ u16 ;
struct sk_buff {int dummy; } ;
struct batadv_priv {int /*<<< orphan*/  distributed_arp_table; } ;
struct batadv_dat_entry {int /*<<< orphan*/  ip; int /*<<< orphan*/  mac_addr; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 scalar_t__ ARPOP_REPLY ; 
 int /*<<< orphan*/  BATADV_DBG_DAT ; 
 int /*<<< orphan*/  atomic_read (int /*<<< orphan*/ *) ; 
 scalar_t__ batadv_arp_get_type (struct batadv_priv*,struct sk_buff*,int) ; 
 int /*<<< orphan*/ * batadv_arp_hw_dst (struct sk_buff*,int) ; 
 int /*<<< orphan*/ * batadv_arp_hw_src (struct sk_buff*,int) ; 
 int /*<<< orphan*/  batadv_arp_ip_dst (struct sk_buff*,int) ; 
 int /*<<< orphan*/  batadv_arp_ip_src (struct sk_buff*,int) ; 
 int /*<<< orphan*/  batadv_bla_check_claim (struct batadv_priv*,int /*<<< orphan*/ *,unsigned short) ; 
 scalar_t__ batadv_compare_eth (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  batadv_dat_entry_add (struct batadv_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,unsigned short) ; 
 struct batadv_dat_entry* batadv_dat_entry_hash_find (struct batadv_priv*,int /*<<< orphan*/ ,unsigned short) ; 
 int /*<<< orphan*/  batadv_dat_entry_put (struct batadv_dat_entry*) ; 
 unsigned short batadv_dat_get_vid (struct sk_buff*,int*) ; 
 int /*<<< orphan*/  batadv_dbg (int /*<<< orphan*/ ,struct batadv_priv*,char*,int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  batadv_dbg_arp (struct batadv_priv*,struct sk_buff*,int,char*) ; 
 int batadv_is_my_client (struct batadv_priv*,int /*<<< orphan*/ *,unsigned short) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 

bool batadv_dat_snoop_incoming_arp_reply(struct batadv_priv *bat_priv,
					 struct sk_buff *skb, int hdr_size)
{
	struct batadv_dat_entry *dat_entry = NULL;
	u16 type;
	__be32 ip_src, ip_dst;
	u8 *hw_src, *hw_dst;
	bool dropped = false;
	unsigned short vid;

	if (!atomic_read(&bat_priv->distributed_arp_table))
		goto out;

	vid = batadv_dat_get_vid(skb, &hdr_size);

	type = batadv_arp_get_type(bat_priv, skb, hdr_size);
	if (type != ARPOP_REPLY)
		goto out;

	batadv_dbg_arp(bat_priv, skb, hdr_size, "Parsing incoming ARP REPLY");

	hw_src = batadv_arp_hw_src(skb, hdr_size);
	ip_src = batadv_arp_ip_src(skb, hdr_size);
	hw_dst = batadv_arp_hw_dst(skb, hdr_size);
	ip_dst = batadv_arp_ip_dst(skb, hdr_size);

	/* If ip_dst is already in cache and has the right mac address,
	 * drop this frame if this ARP reply is destined for us because it's
	 * most probably an ARP reply generated by another node of the DHT.
	 * We have most probably received already a reply earlier. Delivering
	 * this frame would lead to doubled receive of an ARP reply.
	 */
	dat_entry = batadv_dat_entry_hash_find(bat_priv, ip_src, vid);
	if (dat_entry && batadv_compare_eth(hw_src, dat_entry->mac_addr)) {
		batadv_dbg(BATADV_DBG_DAT, bat_priv, "Doubled ARP reply removed: ARP MSG = [src: %pM-%pI4 dst: %pM-%pI4]; dat_entry: %pM-%pI4\n",
			   hw_src, &ip_src, hw_dst, &ip_dst,
			   dat_entry->mac_addr,	&dat_entry->ip);
		dropped = true;
	}

	/* Update our internal cache with both the IP addresses the node got
	 * within the ARP reply
	 */
	batadv_dat_entry_add(bat_priv, ip_src, hw_src, vid);
	batadv_dat_entry_add(bat_priv, ip_dst, hw_dst, vid);

	if (dropped)
		goto out;

	/* If BLA is enabled, only forward ARP replies if we have claimed the
	 * source of the ARP reply or if no one else of the same backbone has
	 * already claimed that client. This prevents that different gateways
	 * to the same backbone all forward the ARP reply leading to multiple
	 * replies in the backbone.
	 */
	if (!batadv_bla_check_claim(bat_priv, hw_src, vid)) {
		batadv_dbg(BATADV_DBG_DAT, bat_priv,
			   "Device %pM claimed by another backbone gw. Drop ARP reply.\n",
			   hw_src);
		dropped = true;
		goto out;
	}

	/* if this REPLY is directed to a client of mine, let's deliver the
	 * packet to the interface
	 */
	dropped = !batadv_is_my_client(bat_priv, hw_dst, vid);

	/* if this REPLY is sent on behalf of a client of mine, let's drop the
	 * packet because the client will reply by itself
	 */
	dropped |= batadv_is_my_client(bat_priv, hw_src, vid);
out:
	if (dropped)
		kfree_skb(skb);
	if (dat_entry)
		batadv_dat_entry_put(dat_entry);
	/* if dropped == false -> deliver to the interface */
	return dropped;
}