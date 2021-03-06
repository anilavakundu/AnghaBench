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
typedef  int /*<<< orphan*/  svn_fs_x__revision_file_t ;
struct TYPE_4__ {int size; } ;
typedef  TYPE_1__ svn_fs_x__p2l_entry_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  apr_size_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int STREAM_THRESHOLD ; 
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SVN_ERR_ASSERT (int) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  expected_checksum (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn__fnv1a_32x4 (unsigned char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_fs_x__rev_file_read (int /*<<< orphan*/ *,unsigned char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static svn_error_t *
expected_buffered_checksum(svn_fs_x__revision_file_t *file,
                           svn_fs_x__p2l_entry_t *entry,
                           apr_pool_t *scratch_pool)
{
  unsigned char buffer[STREAM_THRESHOLD];
  SVN_ERR_ASSERT(entry->size <= STREAM_THRESHOLD);

  SVN_ERR(svn_fs_x__rev_file_read(file, buffer, (apr_size_t)entry->size));
  SVN_ERR(expected_checksum(file, entry,
                            svn__fnv1a_32x4(buffer, (apr_size_t)entry->size),
                            scratch_pool));

  return SVN_NO_ERROR;
}