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
typedef  int /*<<< orphan*/  LONG ;
typedef  scalar_t__ HKEY ;

/* Variables and functions */
 int /*<<< orphan*/  GetLastError () ; 
 scalar_t__ HKEY_CURRENT_USER ; 
 int /*<<< orphan*/  KEY_READ ; 
 int /*<<< orphan*/  RegCloseKey (scalar_t__) ; 
 int /*<<< orphan*/  RegOpenCurrentUser (int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  ok (int,char*,scalar_t__,...) ; 

__attribute__((used)) static void test_RegOpenCurrentUser(void)
{
    HKEY key;
    LONG ret;

    key = HKEY_CURRENT_USER;
    ret = RegOpenCurrentUser(KEY_READ, &key);
    ok(!ret, "got %d, error %d\n", ret, GetLastError());
    ok(key != HKEY_CURRENT_USER, "got %p\n", key);
    RegCloseKey(key);
}