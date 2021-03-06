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
struct sw_flow_actions {int actions_len; } ;

/* Variables and functions */
 int add_action (struct sw_flow_actions**,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int add_nested_action_start(struct sw_flow_actions **sfa, int attrtype)
{
	int used = (*sfa)->actions_len;
	int err;

	err = add_action(sfa, attrtype, NULL, 0);
	if (err)
		return err;

	return used;
}