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
 int /*<<< orphan*/  GIUINTENL ; 
 int /*<<< orphan*/  GIUINTSTATL ; 
 unsigned int GPIO_PIN_OF_IRQ (unsigned int) ; 
 int /*<<< orphan*/  giu_clear (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  giu_write (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void mask_ack_giuint_low(unsigned int irq)
{
	unsigned int pin;

	pin = GPIO_PIN_OF_IRQ(irq);
	giu_clear(GIUINTENL, 1 << pin);
	giu_write(GIUINTSTATL, 1 << pin);
}