#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_oid ;
struct TYPE_3__ {int /*<<< orphan*/  id; } ;
typedef  TYPE_1__ git_index_entry ;
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  cl_repo_set_bool (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  cl_set_cleanup (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cleanup_1397 ; 
 int /*<<< orphan*/  git_index_add_bypath (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 TYPE_1__* git_index_get_bypath (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

void test_index_tests__add_issue_1397(void)
{
	git_index *index;
	git_repository *repo;
	const git_index_entry *entry;
	git_oid id1;

	cl_set_cleanup(&cleanup_1397, NULL);

	repo = cl_git_sandbox_init("issue_1397");

	cl_repo_set_bool(repo, "core.autocrlf", true);

	/* Ensure we're the only guy in the room */
	cl_git_pass(git_repository_index(&index, repo));

	/* Store the expected hash of the file/blob
	 * This has been generated by executing the following
	 * $ git hash-object crlf_file.txt
	 */
	cl_git_pass(git_oid_fromstr(&id1, "8312e0889a9cbab77c732b6bc39b51a683e3a318"));

	/* Make sure the initial SHA-1 is correct */
	cl_assert((entry = git_index_get_bypath(index, "crlf_file.txt", 0)) != NULL);
	cl_assert_equal_oid(&id1, &entry->id);

	/* Update the index */
	cl_git_pass(git_index_add_bypath(index, "crlf_file.txt"));

	/* Check the new SHA-1 */
	cl_assert((entry = git_index_get_bypath(index, "crlf_file.txt", 0)) != NULL);
	cl_assert_equal_oid(&id1, &entry->id);

	git_index_free(index);
}