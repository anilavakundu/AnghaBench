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
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  genl_lock () ; 
 int /*<<< orphan*/  genl_rcv_msg ; 
 int /*<<< orphan*/  genl_unlock () ; 
 int /*<<< orphan*/  netlink_rcv_skb (struct sk_buff*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void genl_rcv(struct sk_buff *skb)
{
	genl_lock();
	netlink_rcv_skb(skb, &genl_rcv_msg);
	genl_unlock();
}