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
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
struct super_block {int dummy; } ;
struct inode {scalar_t__ i_generation; int /*<<< orphan*/ * d_op; int /*<<< orphan*/  root_item; } ;
struct dentry {scalar_t__ i_generation; int /*<<< orphan*/ * d_op; int /*<<< orphan*/  root_item; } ;
struct btrfs_root {scalar_t__ i_generation; int /*<<< orphan*/ * d_op; int /*<<< orphan*/  root_item; } ;
struct btrfs_key {scalar_t__ offset; scalar_t__ objectid; } ;
struct btrfs_fs_info {int /*<<< orphan*/  subvol_srcu; } ;

/* Variables and functions */
 scalar_t__ BTRFS_FIRST_FREE_OBJECTID ; 
 int /*<<< orphan*/  BTRFS_INODE_ITEM_KEY ; 
 int /*<<< orphan*/  BTRFS_ROOT_ITEM_KEY ; 
 int ENOENT ; 
 struct inode* ERR_PTR (int) ; 
 int ESTALE ; 
 scalar_t__ IS_ERR (struct inode*) ; 
 int PTR_ERR (struct inode*) ; 
 int /*<<< orphan*/  btrfs_dentry_operations ; 
 struct inode* btrfs_iget (struct super_block*,struct btrfs_key*,struct inode*,int /*<<< orphan*/ *) ; 
 struct inode* btrfs_read_fs_root_no_name (struct btrfs_fs_info*,struct btrfs_key*) ; 
 scalar_t__ btrfs_root_refs (int /*<<< orphan*/ *) ; 
 struct btrfs_fs_info* btrfs_sb (struct super_block*) ; 
 int /*<<< orphan*/  btrfs_set_key_type (struct btrfs_key*,int /*<<< orphan*/ ) ; 
 struct inode* d_obtain_alias (struct inode*) ; 
 int /*<<< orphan*/  iput (struct inode*) ; 
 int srcu_read_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  srcu_read_unlock (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static struct dentry *btrfs_get_dentry(struct super_block *sb, u64 objectid,
				       u64 root_objectid, u32 generation,
				       int check_generation)
{
	struct btrfs_fs_info *fs_info = btrfs_sb(sb);
	struct btrfs_root *root;
	struct dentry *dentry;
	struct inode *inode;
	struct btrfs_key key;
	int index;
	int err = 0;

	if (objectid < BTRFS_FIRST_FREE_OBJECTID)
		return ERR_PTR(-ESTALE);

	key.objectid = root_objectid;
	btrfs_set_key_type(&key, BTRFS_ROOT_ITEM_KEY);
	key.offset = (u64)-1;

	index = srcu_read_lock(&fs_info->subvol_srcu);

	root = btrfs_read_fs_root_no_name(fs_info, &key);
	if (IS_ERR(root)) {
		err = PTR_ERR(root);
		goto fail;
	}

	if (btrfs_root_refs(&root->root_item) == 0) {
		err = -ENOENT;
		goto fail;
	}

	key.objectid = objectid;
	btrfs_set_key_type(&key, BTRFS_INODE_ITEM_KEY);
	key.offset = 0;

	inode = btrfs_iget(sb, &key, root, NULL);
	if (IS_ERR(inode)) {
		err = PTR_ERR(inode);
		goto fail;
	}

	srcu_read_unlock(&fs_info->subvol_srcu, index);

	if (check_generation && generation != inode->i_generation) {
		iput(inode);
		return ERR_PTR(-ESTALE);
	}

	dentry = d_obtain_alias(inode);
	if (!IS_ERR(dentry))
		dentry->d_op = &btrfs_dentry_operations;
	return dentry;
fail:
	srcu_read_unlock(&fs_info->subvol_srcu, index);
	return ERR_PTR(err);
}