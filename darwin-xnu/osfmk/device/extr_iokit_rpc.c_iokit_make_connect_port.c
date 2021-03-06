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
typedef  int /*<<< orphan*/  ipc_port_t ;
typedef  int /*<<< orphan*/  io_object_t ;

/* Variables and functions */
 int /*<<< orphan*/  IKOT_IOKIT_CONNECT ; 
 int /*<<< orphan*/  iokit_make_port_of_type (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

ipc_port_t
iokit_make_connect_port(
	io_object_t	obj )
{
    return (iokit_make_port_of_type(obj, IKOT_IOKIT_CONNECT));
}