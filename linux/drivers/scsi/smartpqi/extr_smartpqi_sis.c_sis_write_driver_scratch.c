#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct pqi_ctrl_info {TYPE_1__* registers; } ;
struct TYPE_2__ {int /*<<< orphan*/  sis_driver_scratch; } ;

/* Variables and functions */
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void sis_write_driver_scratch(struct pqi_ctrl_info *ctrl_info, u32 value)
{
	writel(value, &ctrl_info->registers->sis_driver_scratch);
}