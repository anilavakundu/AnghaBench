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
struct dmi_system_id {scalar_t__ driver_data; } ;

/* Variables and functions */
 unsigned long rt5670_quirk ; 

__attribute__((used)) static int rt5670_quirk_cb(const struct dmi_system_id *id)
{
	rt5670_quirk = (unsigned long)id->driver_data;
	return 1;
}