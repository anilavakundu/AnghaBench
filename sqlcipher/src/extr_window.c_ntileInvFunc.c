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
struct NtileCtx {int /*<<< orphan*/  iRow; } ;
typedef  int /*<<< orphan*/  sqlite3_value ;
typedef  int /*<<< orphan*/  sqlite3_context ;

/* Variables and functions */
 int /*<<< orphan*/  UNUSED_PARAMETER (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ sqlite3_aggregate_context (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void ntileInvFunc(
  sqlite3_context *pCtx, 
  int nArg,
  sqlite3_value **apArg
){
  struct NtileCtx *p;
  assert( nArg==1 ); UNUSED_PARAMETER(nArg);
  UNUSED_PARAMETER(apArg);
  p = (struct NtileCtx*)sqlite3_aggregate_context(pCtx, sizeof(*p));
  p->iRow++;
}