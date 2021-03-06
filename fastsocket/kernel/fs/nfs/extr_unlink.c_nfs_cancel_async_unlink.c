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
struct nfs_unlinkdata {int dummy; } ;
struct dentry {int d_flags; int /*<<< orphan*/  d_lock; struct nfs_unlinkdata* d_fsdata; } ;

/* Variables and functions */
 int DCACHE_NFSFS_RENAMED ; 
 int /*<<< orphan*/  nfs_free_unlinkdata (struct nfs_unlinkdata*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
nfs_cancel_async_unlink(struct dentry *dentry)
{
	spin_lock(&dentry->d_lock);
	if (dentry->d_flags & DCACHE_NFSFS_RENAMED) {
		struct nfs_unlinkdata *data = dentry->d_fsdata;

		dentry->d_flags &= ~DCACHE_NFSFS_RENAMED;
		spin_unlock(&dentry->d_lock);
		nfs_free_unlinkdata(data);
		return;
	}
	spin_unlock(&dentry->d_lock);
}