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
struct comedi_device {scalar_t__ irq; int /*<<< orphan*/  minor; } ;

/* Variables and functions */
 int /*<<< orphan*/  free_irq (scalar_t__,struct comedi_device*) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int das16cs_detach(struct comedi_device *dev)
{
	printk("comedi%d: das16cs: remove\n", dev->minor);

	if (dev->irq) {
		free_irq(dev->irq, dev);
	}

	return 0;
}