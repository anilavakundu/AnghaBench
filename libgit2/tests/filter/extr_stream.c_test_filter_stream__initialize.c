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
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  compress_filter ; 
 int /*<<< orphan*/  create_compress_filter () ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_filter_register (char*,int /*<<< orphan*/ ,int) ; 

void test_filter_stream__initialize(void)
{
	compress_filter = create_compress_filter();

	cl_git_pass(git_filter_register("compress", compress_filter, 50));
	g_repo = cl_git_sandbox_init("empty_standard_repo");
}