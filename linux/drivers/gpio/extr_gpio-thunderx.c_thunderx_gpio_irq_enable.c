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
struct irq_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  irq_chip_enable_parent (struct irq_data*) ; 
 int /*<<< orphan*/  thunderx_gpio_irq_unmask (struct irq_data*) ; 

__attribute__((used)) static void thunderx_gpio_irq_enable(struct irq_data *data)
{
	irq_chip_enable_parent(data);
	thunderx_gpio_irq_unmask(data);
}