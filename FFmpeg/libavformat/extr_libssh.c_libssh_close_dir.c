#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_2__* priv_data; } ;
typedef  TYPE_1__ URLContext ;
struct TYPE_6__ {int /*<<< orphan*/ * dir; } ;
typedef  TYPE_2__ LIBSSHContext ;

/* Variables and functions */
 int /*<<< orphan*/  libssh_close (TYPE_1__*) ; 
 int /*<<< orphan*/  sftp_closedir (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int libssh_close_dir(URLContext *h)
{
    LIBSSHContext *libssh = h->priv_data;
    if (libssh->dir)
        sftp_closedir(libssh->dir);
    libssh->dir = NULL;
    libssh_close(h);
    return 0;
}