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
struct fuse_file_info {scalar_t__ fh; } ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int closedir (int /*<<< orphan*/ *) ; 
 int errno ; 

__attribute__((used)) static int pifs_releasedir(const char *path, struct fuse_file_info *info)
{
  int ret = closedir((DIR *)info->fh);
  return ret == -1 ? -errno : ret;
}