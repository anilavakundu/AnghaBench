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
struct nf_conn {int status; } ;

/* Variables and functions */
 int IPS_SRC_NAT_DONE ; 
 int /*<<< orphan*/  __nf_nat_cleanup_conntrack (struct nf_conn*) ; 

__attribute__((used)) static void nf_nat_cleanup_conntrack(struct nf_conn *ct)
{
	if (ct->status & IPS_SRC_NAT_DONE)
		__nf_nat_cleanup_conntrack(ct);
}