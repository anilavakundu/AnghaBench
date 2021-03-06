#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_2__* p_sys; } ;
typedef  TYPE_1__ stream_t ;
struct TYPE_7__ {int /*<<< orphan*/  url; int /*<<< orphan*/  proxy; scalar_t__ b_proxy; struct TYPE_7__* p_header; } ;
typedef  TYPE_2__ access_sys_t ;

/* Variables and functions */
 int /*<<< orphan*/  Stop (TYPE_1__*) ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  vlc_UrlClean (int /*<<< orphan*/ *) ; 

void  MMSHClose ( stream_t *p_access )
{
    access_sys_t *p_sys = p_access->p_sys;

    Stop( p_access );

    free( p_sys->p_header );

    if( p_sys->b_proxy )
        vlc_UrlClean( &p_sys->proxy );
    vlc_UrlClean( &p_sys->url );
    free( p_sys );
}