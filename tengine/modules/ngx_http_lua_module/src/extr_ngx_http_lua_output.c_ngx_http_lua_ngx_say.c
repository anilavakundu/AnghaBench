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
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  dd (char*) ; 
 int ngx_http_lua_ngx_echo (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int
ngx_http_lua_ngx_say(lua_State *L)
{
    dd("calling");
    return ngx_http_lua_ngx_echo(L, 1);
}