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
typedef  int /*<<< orphan*/  StringInfo ;
typedef  int /*<<< orphan*/  PathKey ;

/* Variables and functions */
 int /*<<< orphan*/  WRITE_BOOL_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_INT_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_NODE_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_NODE_TYPE (char*) ; 
 int /*<<< orphan*/  WRITE_OID_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pk_eclass ; 
 int /*<<< orphan*/  pk_nulls_first ; 
 int /*<<< orphan*/  pk_opfamily ; 
 int /*<<< orphan*/  pk_strategy ; 

__attribute__((used)) static void
_outPathKey(StringInfo str, const PathKey *node)
{
	WRITE_NODE_TYPE("PATHKEY");

	WRITE_NODE_FIELD(pk_eclass);
	WRITE_OID_FIELD(pk_opfamily);
	WRITE_INT_FIELD(pk_strategy);
	WRITE_BOOL_FIELD(pk_nulls_first);
}