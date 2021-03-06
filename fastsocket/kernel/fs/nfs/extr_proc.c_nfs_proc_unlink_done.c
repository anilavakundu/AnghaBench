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
struct rpc_task {int dummy; } ;
struct inode {int dummy; } ;

/* Variables and functions */
 scalar_t__ nfs_async_handle_expired_key (struct rpc_task*) ; 
 int /*<<< orphan*/  nfs_mark_for_revalidate (struct inode*) ; 

__attribute__((used)) static int nfs_proc_unlink_done(struct rpc_task *task, struct inode *dir)
{
	if (nfs_async_handle_expired_key(task))
		return 0;
	nfs_mark_for_revalidate(dir);
	return 1;
}