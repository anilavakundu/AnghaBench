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
struct writeback_control {int dummy; } ;
struct address_space {int dummy; } ;

/* Variables and functions */
 int mpage_writepages (struct address_space*,struct writeback_control*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omfs_get_block ; 

__attribute__((used)) static int
omfs_writepages(struct address_space *mapping, struct writeback_control *wbc)
{
	return mpage_writepages(mapping, wbc, omfs_get_block);
}