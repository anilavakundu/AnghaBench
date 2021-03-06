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
struct mxt_data {int suspend_mode; } ;

/* Variables and functions */
 int /*<<< orphan*/  MXT_POWER_CFG_DEEPSLEEP ; 
#define  MXT_SUSPEND_DEEP_SLEEP 129 
#define  MXT_SUSPEND_T9_CTRL 128 
 int /*<<< orphan*/  MXT_T9_CTRL ; 
 int /*<<< orphan*/  MXT_TOUCH_MULTI_T9 ; 
 int /*<<< orphan*/  mxt_set_t7_power_cfg (struct mxt_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mxt_write_object (struct mxt_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void mxt_stop(struct mxt_data *data)
{
	switch (data->suspend_mode) {
	case MXT_SUSPEND_T9_CTRL:
		/* Touch disable */
		mxt_write_object(data,
				MXT_TOUCH_MULTI_T9, MXT_T9_CTRL, 0);
		break;

	case MXT_SUSPEND_DEEP_SLEEP:
	default:
		mxt_set_t7_power_cfg(data, MXT_POWER_CFG_DEEPSLEEP);
		break;
	}
}