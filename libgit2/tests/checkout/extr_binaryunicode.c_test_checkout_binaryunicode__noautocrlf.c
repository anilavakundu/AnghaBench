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

/* Variables and functions */
 int /*<<< orphan*/  cl_repo_set_bool (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  execute_test () ; 
 int /*<<< orphan*/  g_repo ; 

void test_checkout_binaryunicode__noautocrlf(void)
{
	cl_repo_set_bool(g_repo, "core.autocrlf", false);
	execute_test();
}