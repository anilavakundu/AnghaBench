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
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mcu_gpio_set (struct gpio_chip*,unsigned int,int) ; 

__attribute__((used)) static int mcu_gpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
	mcu_gpio_set(gc, gpio, val);
	return 0;
}