#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {unsigned int iops; } ;
struct blkio_policy_node {TYPE_1__ val; } ;
struct blkio_cgroup {int dummy; } ;
typedef  int /*<<< orphan*/  dev_t ;

/* Variables and functions */
 int /*<<< orphan*/  BLKIO_POLICY_THROTL ; 
 int /*<<< orphan*/  BLKIO_THROTL_read_iops_device ; 
 struct blkio_policy_node* blkio_policy_search_node (struct blkio_cgroup*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

unsigned int blkcg_get_read_iops(struct blkio_cgroup *blkcg, dev_t dev)
{
	struct blkio_policy_node *pn;

	pn = blkio_policy_search_node(blkcg, dev, BLKIO_POLICY_THROTL,
				BLKIO_THROTL_read_iops_device);
	if (pn)
		return pn->val.iops;
	else
		return -1;
}