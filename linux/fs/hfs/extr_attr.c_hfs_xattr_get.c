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
struct xattr_handler {int /*<<< orphan*/  flags; } ;
struct inode {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int __hfs_getxattr (struct inode*,int /*<<< orphan*/ ,void*,size_t) ; 

__attribute__((used)) static int hfs_xattr_get(const struct xattr_handler *handler,
			 struct dentry *unused, struct inode *inode,
			 const char *name, void *value, size_t size)
{
	return __hfs_getxattr(inode, handler->flags, value, size);
}