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
struct regmap {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 unsigned long CTZ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SKY81452_EN ; 
 int /*<<< orphan*/  SKY81452_REG1 ; 
 struct regmap* bl_get_data (int /*<<< orphan*/ ) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  to_backlight_device (struct device*) ; 

__attribute__((used)) static ssize_t sky81452_bl_store_enable(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct regmap *regmap = bl_get_data(to_backlight_device(dev));
	unsigned long value;
	int ret;

	ret = kstrtoul(buf, 16, &value);
	if (ret < 0)
		return ret;

	ret = regmap_update_bits(regmap, SKY81452_REG1, SKY81452_EN,
					value << CTZ(SKY81452_EN));
	if (ret < 0)
		return ret;

	return count;
}