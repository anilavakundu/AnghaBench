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
struct dm_table {int /*<<< orphan*/  md; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMERR (char*) ; 
 int dm_table_alloc_md_mempools (struct dm_table*) ; 
 int dm_table_build_index (struct dm_table*) ; 
 int dm_table_prealloc_integrity (struct dm_table*,int /*<<< orphan*/ ) ; 
 int dm_table_set_type (struct dm_table*) ; 

int dm_table_complete(struct dm_table *t)
{
	int r;

	r = dm_table_set_type(t);
	if (r) {
		DMERR("unable to set table type");
		return r;
	}

	r = dm_table_build_index(t);
	if (r) {
		DMERR("unable to build btrees");
		return r;
	}

	r = dm_table_prealloc_integrity(t, t->md);
	if (r) {
		DMERR("could not register integrity profile.");
		return r;
	}

	r = dm_table_alloc_md_mempools(t);
	if (r)
		DMERR("unable to allocate mempools");

	return r;
}