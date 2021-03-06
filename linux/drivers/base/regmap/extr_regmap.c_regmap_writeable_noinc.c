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
struct regmap {int (* writeable_noinc_reg ) (int /*<<< orphan*/ ,unsigned int) ;scalar_t__ wr_noinc_table; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int regmap_check_range_table (struct regmap*,unsigned int,scalar_t__) ; 
 int stub1 (int /*<<< orphan*/ ,unsigned int) ; 

bool regmap_writeable_noinc(struct regmap *map, unsigned int reg)
{
	if (map->writeable_noinc_reg)
		return map->writeable_noinc_reg(map->dev, reg);

	if (map->wr_noinc_table)
		return regmap_check_range_table(map, reg, map->wr_noinc_table);

	return true;
}