#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct tmp401_data {int /*<<< orphan*/  config; int /*<<< orphan*/ ** temp; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {int nr; int index; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct tmp401_data*) ; 
 int /*<<< orphan*/  PTR_ERR (struct tmp401_data*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int tmp401_register_to_temp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct tmp401_data* tmp401_update_device (struct device*) ; 
 TYPE_1__* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static ssize_t temp_show(struct device *dev, struct device_attribute *devattr,
			 char *buf)
{
	int nr = to_sensor_dev_attr_2(devattr)->nr;
	int index = to_sensor_dev_attr_2(devattr)->index;
	struct tmp401_data *data = tmp401_update_device(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n",
		tmp401_register_to_temp(data->temp[nr][index], data->config));
}