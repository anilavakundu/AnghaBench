#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vlc_object_t ;
struct TYPE_3__ {int /*<<< orphan*/ * pf_readdir; TYPE_2__* p_sys; } ;
typedef  TYPE_1__ stream_t ;
struct TYPE_4__ {int /*<<< orphan*/  i_smb; int /*<<< orphan*/  url; } ;
typedef  TYPE_2__ access_sys_t ;

/* Variables and functions */
 int /*<<< orphan*/  smbc_close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smbc_closedir (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_UrlClean (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void Close(vlc_object_t *obj)
{
    stream_t *access = (stream_t *)obj;
    access_sys_t *sys = access->p_sys;

    vlc_UrlClean(&sys->url);

    if (access->pf_readdir != NULL)
        smbc_closedir(sys->i_smb);
    else
        smbc_close(sys->i_smb);
}