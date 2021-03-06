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
typedef  int /*<<< orphan*/  uint64_t ;
struct TYPE_2__ {int /*<<< orphan*/  i_size; } ;
struct nfs_inode {TYPE_1__ vfs_inode; } ;

/* Variables and functions */

__attribute__((used)) static void nfs_fscache_inode_get_attr(const void *cookie_netfs_data,
				       uint64_t *size)
{
	const struct nfs_inode *nfsi = cookie_netfs_data;

	*size = nfsi->vfs_inode.i_size;
}