#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_loop_t ;
struct TYPE_6__ {int file_flags; } ;
struct TYPE_7__ {TYPE_1__ info; } ;
struct TYPE_8__ {TYPE_2__ fs; } ;
typedef  TYPE_3__ uv_fs_t ;
typedef  int /*<<< orphan*/ * uv_fs_cb ;

/* Variables and functions */
 int /*<<< orphan*/  INIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  POST ; 
 int UV_EINVAL ; 
 int /*<<< orphan*/  UV_FS_COPYFILE ; 
 int UV_FS_COPYFILE_EXCL ; 
 int UV_FS_COPYFILE_FICLONE ; 
 int UV_FS_COPYFILE_FICLONE_FORCE ; 
 int fs__capture_path (TYPE_3__*,char const*,char const*,int /*<<< orphan*/ ) ; 
 int uv_translate_sys_error (int) ; 

int uv_fs_copyfile(uv_loop_t* loop,
                   uv_fs_t* req,
                   const char* path,
                   const char* new_path,
                   int flags,
                   uv_fs_cb cb) {
  int err;

  INIT(UV_FS_COPYFILE);

  if (flags & ~(UV_FS_COPYFILE_EXCL |
                UV_FS_COPYFILE_FICLONE |
                UV_FS_COPYFILE_FICLONE_FORCE)) {
    return UV_EINVAL;
  }

  err = fs__capture_path(req, path, new_path, cb != NULL);

  if (err)
    return uv_translate_sys_error(err);

  req->fs.info.file_flags = flags;
  POST;
}