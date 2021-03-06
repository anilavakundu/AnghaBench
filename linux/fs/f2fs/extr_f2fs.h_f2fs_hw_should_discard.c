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
struct f2fs_sb_info {int dummy; } ;

/* Variables and functions */
 int f2fs_sb_has_blkzoned (struct f2fs_sb_info*) ; 

__attribute__((used)) static inline bool f2fs_hw_should_discard(struct f2fs_sb_info *sbi)
{
	return f2fs_sb_has_blkzoned(sbi);
}