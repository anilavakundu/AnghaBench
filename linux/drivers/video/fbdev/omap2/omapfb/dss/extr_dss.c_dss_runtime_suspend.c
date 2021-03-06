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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dss_save_context () ; 
 int /*<<< orphan*/  dss_set_min_bus_tput (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pinctrl_pm_select_sleep_state (struct device*) ; 

__attribute__((used)) static int dss_runtime_suspend(struct device *dev)
{
	dss_save_context();
	dss_set_min_bus_tput(dev, 0);

	pinctrl_pm_select_sleep_state(dev);

	return 0;
}