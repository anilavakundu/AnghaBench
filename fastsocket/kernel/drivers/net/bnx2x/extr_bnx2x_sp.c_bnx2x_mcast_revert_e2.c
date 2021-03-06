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
struct bnx2x_mcast_ramrod_params {scalar_t__ mcast_list_len; struct bnx2x_mcast_obj* mcast_obj; } ;
struct bnx2x_mcast_obj {int /*<<< orphan*/  total_pending_num; int /*<<< orphan*/  (* set_registry_size ) (struct bnx2x_mcast_obj*,int) ;} ;
struct bnx2x {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct bnx2x_mcast_obj*,int) ; 

__attribute__((used)) static void bnx2x_mcast_revert_e2(struct bnx2x *bp,
				      struct bnx2x_mcast_ramrod_params *p,
				      int old_num_bins)
{
	struct bnx2x_mcast_obj *o = p->mcast_obj;

	o->set_registry_size(o, old_num_bins);
	o->total_pending_num -= p->mcast_list_len;
}