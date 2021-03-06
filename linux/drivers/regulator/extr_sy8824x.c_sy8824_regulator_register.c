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
struct regulator_desc {char* name; char* supply_name; int /*<<< orphan*/  owner; scalar_t__ vsel_mask; int /*<<< orphan*/  vsel_reg; int /*<<< orphan*/  uV_step; int /*<<< orphan*/  min_uV; int /*<<< orphan*/  enable_mask; int /*<<< orphan*/  enable_reg; scalar_t__ n_voltages; int /*<<< orphan*/  type; int /*<<< orphan*/ * ops; } ;
struct sy8824_device_info {struct regulator_desc desc; int /*<<< orphan*/  dev; struct sy8824_config* cfg; } ;
struct sy8824_config {scalar_t__ vsel_count; int /*<<< orphan*/  vol_reg; int /*<<< orphan*/  vsel_step; int /*<<< orphan*/  vsel_min; int /*<<< orphan*/  enable_reg; } ;
struct regulator_dev {int dummy; } ;
struct regulator_config {int dummy; } ;

/* Variables and functions */
 int PTR_ERR_OR_ZERO (struct regulator_dev*) ; 
 int /*<<< orphan*/  REGULATOR_VOLTAGE ; 
 int /*<<< orphan*/  SY8824C_BUCK_EN ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 struct regulator_dev* devm_regulator_register (int /*<<< orphan*/ ,struct regulator_desc*,struct regulator_config*) ; 
 int /*<<< orphan*/  sy8824_regulator_ops ; 

__attribute__((used)) static int sy8824_regulator_register(struct sy8824_device_info *di,
			struct regulator_config *config)
{
	struct regulator_desc *rdesc = &di->desc;
	const struct sy8824_config *cfg = di->cfg;
	struct regulator_dev *rdev;

	rdesc->name = "sy8824-reg";
	rdesc->supply_name = "vin";
	rdesc->ops = &sy8824_regulator_ops;
	rdesc->type = REGULATOR_VOLTAGE;
	rdesc->n_voltages = cfg->vsel_count;
	rdesc->enable_reg = cfg->enable_reg;
	rdesc->enable_mask = SY8824C_BUCK_EN;
	rdesc->min_uV = cfg->vsel_min;
	rdesc->uV_step = cfg->vsel_step;
	rdesc->vsel_reg = cfg->vol_reg;
	rdesc->vsel_mask = cfg->vsel_count - 1;
	rdesc->owner = THIS_MODULE;

	rdev = devm_regulator_register(di->dev, &di->desc, config);
	return PTR_ERR_OR_ZERO(rdev);
}