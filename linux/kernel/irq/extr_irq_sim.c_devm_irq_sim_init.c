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
struct irq_sim_devres {struct irq_sim* sim; } ;
struct irq_sim {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  devm_irq_sim_release ; 
 int /*<<< orphan*/  devres_add (struct device*,struct irq_sim_devres*) ; 
 struct irq_sim_devres* devres_alloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devres_free (struct irq_sim_devres*) ; 
 int irq_sim_init (struct irq_sim*,unsigned int) ; 

int devm_irq_sim_init(struct device *dev, struct irq_sim *sim,
		      unsigned int num_irqs)
{
	struct irq_sim_devres *dr;
	int rv;

	dr = devres_alloc(devm_irq_sim_release, sizeof(*dr), GFP_KERNEL);
	if (!dr)
		return -ENOMEM;

	rv = irq_sim_init(sim, num_irqs);
	if (rv < 0) {
		devres_free(dr);
		return rv;
	}

	dr->sim = sim;
	devres_add(dev, dr);

	return rv;
}