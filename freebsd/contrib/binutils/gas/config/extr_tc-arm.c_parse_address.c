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
 int FAIL ; 
 scalar_t__ PARSE_OPERAND_SUCCESS ; 
 int SUCCESS ; 
 scalar_t__ parse_address_main (char**,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
parse_address (char **str, int i)
{
  return parse_address_main (str, i, 0, 0) == PARSE_OPERAND_SUCCESS
         ? SUCCESS : FAIL;
}