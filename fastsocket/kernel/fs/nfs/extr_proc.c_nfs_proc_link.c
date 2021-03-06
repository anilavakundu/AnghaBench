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
struct rpc_message {struct nfs_linkargs* rpc_argp; int /*<<< orphan*/ * rpc_proc; } ;
struct qstr {int name; int /*<<< orphan*/  len; } ;
struct nfs_linkargs {int toname; int /*<<< orphan*/  tolen; int /*<<< orphan*/  tofh; int /*<<< orphan*/  fromfh; } ;
struct inode {int dummy; } ;

/* Variables and functions */
 size_t NFSPROC_LINK ; 
 int /*<<< orphan*/  NFS_CLIENT (struct inode*) ; 
 int /*<<< orphan*/  NFS_FH (struct inode*) ; 
 int /*<<< orphan*/  dprintk (char*,int) ; 
 int /*<<< orphan*/  nfs_mark_for_revalidate (struct inode*) ; 
 int /*<<< orphan*/ * nfs_procedures ; 
 int rpc_call_sync (int /*<<< orphan*/ ,struct rpc_message*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
nfs_proc_link(struct inode *inode, struct inode *dir, struct qstr *name)
{
	struct nfs_linkargs	arg = {
		.fromfh		= NFS_FH(inode),
		.tofh		= NFS_FH(dir),
		.toname		= name->name,
		.tolen		= name->len
	};
	struct rpc_message msg = {
		.rpc_proc	= &nfs_procedures[NFSPROC_LINK],
		.rpc_argp	= &arg,
	};
	int			status;

	dprintk("NFS call  link %s\n", name->name);
	status = rpc_call_sync(NFS_CLIENT(inode), &msg, 0);
	nfs_mark_for_revalidate(inode);
	nfs_mark_for_revalidate(dir);
	dprintk("NFS reply link: %d\n", status);
	return status;
}