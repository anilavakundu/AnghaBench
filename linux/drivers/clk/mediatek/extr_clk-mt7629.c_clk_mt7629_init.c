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
 int /*<<< orphan*/  clk_mt7629_drv ; 
 int platform_driver_register (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int clk_mt7629_init(void)
{
	return platform_driver_register(&clk_mt7629_drv);
}