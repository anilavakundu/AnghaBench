#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct status_entry {int member_0; char* member_1; char* member_2; } ;
struct TYPE_4__ {int /*<<< orphan*/  flags; } ;
typedef  TYPE_1__ git_status_options ;
typedef  int /*<<< orphan*/  git_status_list ;
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 int GIT_INDEX_CAPABILITY_IGNORE_CASE ; 
 int GIT_STATUS_INDEX_MODIFIED ; 
 int GIT_STATUS_INDEX_RENAMED ; 
 TYPE_1__ GIT_STATUS_OPTIONS_INIT ; 
 int /*<<< orphan*/  GIT_STATUS_OPT_INCLUDE_UNTRACKED ; 
 int /*<<< orphan*/  GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX ; 
 int /*<<< orphan*/  GIT_STATUS_OPT_RENAMES_INDEX_TO_WORKDIR ; 
 int GIT_STATUS_WT_MODIFIED ; 
 int GIT_STATUS_WT_RENAMED ; 
 int /*<<< orphan*/  check_status (int /*<<< orphan*/ *,struct status_entry*,int) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_index_add_bypath (int /*<<< orphan*/ *,char*) ; 
 int git_index_caps (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_remove_bypath (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_index_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_status_list_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_status_list_new (int /*<<< orphan*/ **,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  rename_and_edit_file (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  rename_file (int /*<<< orphan*/ ,char*,char*) ; 

void test_status_renames__both_casechange_two(void)
{
	git_index *index;
	git_status_list *statuslist;
	git_status_options opts = GIT_STATUS_OPTIONS_INIT;
	int index_caps;
	struct status_entry expected_icase[] = {
		{ GIT_STATUS_INDEX_RENAMED | GIT_STATUS_INDEX_MODIFIED |
		  GIT_STATUS_WT_MODIFIED,
		  "ikeepsix.txt", "IKeepSix.txt" },
		{ GIT_STATUS_INDEX_MODIFIED,
		  "sixserving.txt", "sixserving.txt" },
		{ GIT_STATUS_INDEX_RENAMED | GIT_STATUS_WT_MODIFIED,
		  "songof7cities.txt", "songof7.txt" },
		{ GIT_STATUS_INDEX_RENAMED | GIT_STATUS_WT_RENAMED,
		  "untimely.txt", "untimeliest.txt" }
	};
	struct status_entry expected_case[] = {
		{ GIT_STATUS_INDEX_RENAMED |
		  GIT_STATUS_WT_MODIFIED | GIT_STATUS_WT_RENAMED,
		  "songof7cities.txt", "SONGOF7.txt" },
		{ GIT_STATUS_INDEX_MODIFIED | GIT_STATUS_WT_RENAMED,
		  "sixserving.txt", "SixServing.txt" },
		{ GIT_STATUS_INDEX_RENAMED | GIT_STATUS_INDEX_MODIFIED |
		  GIT_STATUS_WT_RENAMED | GIT_STATUS_WT_MODIFIED,
		  "ikeepsix.txt", "ikeepsix.txt" },
		{ GIT_STATUS_INDEX_RENAMED | GIT_STATUS_WT_RENAMED,
		  "untimely.txt", "untimeliest.txt" }
	};

	opts.flags |= GIT_STATUS_OPT_INCLUDE_UNTRACKED;
	opts.flags |= GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX;
	opts.flags |= GIT_STATUS_OPT_RENAMES_INDEX_TO_WORKDIR;

	cl_git_pass(git_repository_index(&index, g_repo));
	index_caps = git_index_caps(index);

	rename_and_edit_file(g_repo, "ikeepsix.txt", "IKeepSix.txt");
	rename_and_edit_file(g_repo, "sixserving.txt", "sixserving.txt");
	rename_file(g_repo, "songof7cities.txt", "songof7.txt");
	rename_file(g_repo, "untimely.txt", "untimelier.txt");

	cl_git_pass(git_index_remove_bypath(index, "ikeepsix.txt"));
	cl_git_pass(git_index_remove_bypath(index, "sixserving.txt"));
	cl_git_pass(git_index_remove_bypath(index, "songof7cities.txt"));
	cl_git_pass(git_index_remove_bypath(index, "untimely.txt"));
	cl_git_pass(git_index_add_bypath(index, "IKeepSix.txt"));
	cl_git_pass(git_index_add_bypath(index, "sixserving.txt"));
	cl_git_pass(git_index_add_bypath(index, "songof7.txt"));
	cl_git_pass(git_index_add_bypath(index, "untimelier.txt"));
	cl_git_pass(git_index_write(index));

	rename_and_edit_file(g_repo, "IKeepSix.txt", "ikeepsix.txt");
	rename_file(g_repo, "sixserving.txt", "SixServing.txt");
	rename_and_edit_file(g_repo, "songof7.txt", "SONGOF7.txt");
	rename_file(g_repo, "untimelier.txt", "untimeliest.txt");

	cl_git_pass(git_status_list_new(&statuslist, g_repo, &opts));

	check_status(statuslist, (index_caps & GIT_INDEX_CAPABILITY_IGNORE_CASE) ?
		expected_icase : expected_case, 4);

	git_status_list_free(statuslist);

	git_index_free(index);
}