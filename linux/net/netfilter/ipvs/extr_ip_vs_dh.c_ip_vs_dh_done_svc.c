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
struct ip_vs_service {struct ip_vs_dh_state* sched_data; } ;
struct ip_vs_dh_state {int dummy; } ;
struct ip_vs_dh_bucket {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IP_VS_DBG (int,char*,int) ; 
 int IP_VS_DH_TAB_SIZE ; 
 int /*<<< orphan*/  ip_vs_dh_flush (struct ip_vs_dh_state*) ; 
 int /*<<< orphan*/  kfree_rcu (struct ip_vs_dh_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_head ; 

__attribute__((used)) static void ip_vs_dh_done_svc(struct ip_vs_service *svc)
{
	struct ip_vs_dh_state *s = svc->sched_data;

	/* got to clean up hash buckets here */
	ip_vs_dh_flush(s);

	/* release the table itself */
	kfree_rcu(s, rcu_head);
	IP_VS_DBG(6, "DH hash table (memory=%zdbytes) released\n",
		  sizeof(struct ip_vs_dh_bucket)*IP_VS_DH_TAB_SIZE);
}