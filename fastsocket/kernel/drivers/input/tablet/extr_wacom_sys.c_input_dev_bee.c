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
struct wacom_wac {int dummy; } ;
struct input_dev {int* keybit; } ;

/* Variables and functions */
 int BIT_MASK (int /*<<< orphan*/ ) ; 
 size_t BIT_WORD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BTN_8 ; 
 int /*<<< orphan*/  BTN_9 ; 
 int /*<<< orphan*/  BTN_MISC ; 

void input_dev_bee(struct input_dev *input_dev, struct wacom_wac *wacom_wac)
{
	input_dev->keybit[BIT_WORD(BTN_MISC)] |= BIT_MASK(BTN_8) | BIT_MASK(BTN_9);
}