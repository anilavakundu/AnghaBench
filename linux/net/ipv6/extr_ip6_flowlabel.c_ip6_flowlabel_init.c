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

/* Variables and functions */
 int /*<<< orphan*/  ip6_flowlabel_net_ops ; 
 int register_pernet_subsys (int /*<<< orphan*/ *) ; 

int ip6_flowlabel_init(void)
{
	return register_pernet_subsys(&ip6_flowlabel_net_ops);
}