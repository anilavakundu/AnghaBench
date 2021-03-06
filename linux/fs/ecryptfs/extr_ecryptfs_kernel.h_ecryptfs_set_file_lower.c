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
struct file {scalar_t__ private_data; } ;
struct ecryptfs_file_info {struct file* wfi_file; } ;

/* Variables and functions */

__attribute__((used)) static inline void
ecryptfs_set_file_lower(struct file *file, struct file *lower_file)
{
	((struct ecryptfs_file_info *)file->private_data)->wfi_file =
		lower_file;
}