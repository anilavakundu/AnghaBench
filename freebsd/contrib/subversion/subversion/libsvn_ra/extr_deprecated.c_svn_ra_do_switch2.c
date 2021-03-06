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
typedef  int /*<<< orphan*/  svn_revnum_t ;
typedef  int /*<<< orphan*/  svn_ra_session_t ;
typedef  int /*<<< orphan*/  svn_ra_reporter3_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  svn_depth_t ;
typedef  int /*<<< orphan*/  svn_delta_editor_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/ * svn_error_trace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_ra_do_switch3 (int /*<<< orphan*/ *,int /*<<< orphan*/  const**,void**,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,void*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

svn_error_t *
svn_ra_do_switch2(svn_ra_session_t *session,
                  const svn_ra_reporter3_t **reporter,
                  void **report_baton,
                  svn_revnum_t revision_to_switch_to,
                  const char *switch_target,
                  svn_depth_t depth,
                  const char *switch_url,
                  const svn_delta_editor_t *switch_editor,
                  void *switch_baton,
                  apr_pool_t *pool)
{
  return svn_error_trace(
            svn_ra_do_switch3(session,
                              reporter, report_baton,
                              revision_to_switch_to, switch_target,
                              depth,
                              switch_url,
                              FALSE /* send_copyfrom_args */,
                              TRUE /* ignore_ancestry */,
                              switch_editor, switch_baton,
                              pool, pool));
}