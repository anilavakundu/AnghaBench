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
typedef  int /*<<< orphan*/  CreateUserMappingStmt ;

/* Variables and functions */
 int /*<<< orphan*/  COMPARE_NODE_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_SCALAR_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_STRING_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  if_not_exists ; 
 int /*<<< orphan*/  options ; 
 int /*<<< orphan*/  servername ; 
 int /*<<< orphan*/  user ; 

__attribute__((used)) static bool
_equalCreateUserMappingStmt(const CreateUserMappingStmt *a, const CreateUserMappingStmt *b)
{
	COMPARE_NODE_FIELD(user);
	COMPARE_STRING_FIELD(servername);
	COMPARE_SCALAR_FIELD(if_not_exists);
	COMPARE_NODE_FIELD(options);

	return true;
}