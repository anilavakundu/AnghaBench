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
struct dm_thin_device {int changed; int /*<<< orphan*/  mapped_blocks; int /*<<< orphan*/  id; struct dm_pool_metadata* pmd; } ;
struct dm_pool_metadata {int /*<<< orphan*/  root; int /*<<< orphan*/  info; int /*<<< orphan*/  time; } ;
typedef  int /*<<< orphan*/  dm_block_t ;
typedef  int /*<<< orphan*/  __le64 ;

/* Variables and functions */
 int /*<<< orphan*/  __dm_bless_for_disk (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_to_le64 (int /*<<< orphan*/ ) ; 
 int dm_btree_insert_notify (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  pack_block_time (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int __insert(struct dm_thin_device *td, dm_block_t block,
		    dm_block_t data_block)
{
	int r, inserted;
	__le64 value;
	struct dm_pool_metadata *pmd = td->pmd;
	dm_block_t keys[2] = { td->id, block };

	value = cpu_to_le64(pack_block_time(data_block, pmd->time));
	__dm_bless_for_disk(&value);

	r = dm_btree_insert_notify(&pmd->info, pmd->root, keys, &value,
				   &pmd->root, &inserted);
	if (r)
		return r;

	td->changed = 1;
	if (inserted)
		td->mapped_blocks++;

	return 0;
}