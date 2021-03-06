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
typedef  int u_int16_t ;
struct net_device {int dummy; } ;
struct net {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int inet_dev_addr_type (struct net*,struct net_device const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool match_type(struct net *net, const struct net_device *dev,
			      __be32 addr, u_int16_t mask)
{
	return !!(mask & (1 << inet_dev_addr_type(net, dev, addr)));
}