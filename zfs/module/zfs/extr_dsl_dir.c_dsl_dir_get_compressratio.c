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
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  dsl_dir_t ;
struct TYPE_2__ {int dd_compressed_bytes; int dd_uncompressed_bytes; } ;

/* Variables and functions */
 TYPE_1__* dsl_dir_phys (int /*<<< orphan*/ *) ; 

uint64_t
dsl_dir_get_compressratio(dsl_dir_t *dd)
{
	/* a fixed point number, 100x the ratio */
	return (dsl_dir_phys(dd)->dd_compressed_bytes == 0 ? 100 :
	    (dsl_dir_phys(dd)->dd_uncompressed_bytes * 100 /
	    dsl_dir_phys(dd)->dd_compressed_bytes));
}