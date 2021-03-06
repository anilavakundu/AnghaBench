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
struct TYPE_2__ {struct usbip_exported_device* (* get_device ) (struct usbip_host_driver*,int) ;} ;
struct usbip_host_driver {TYPE_1__ ops; } ;
struct usbip_exported_device {int dummy; } ;

/* Variables and functions */
 struct usbip_exported_device* stub1 (struct usbip_host_driver*,int) ; 

__attribute__((used)) static inline struct usbip_exported_device *
usbip_get_device(struct usbip_host_driver *hdriver, int num)
{
	if (!hdriver->ops.get_device)
		return NULL;
	return hdriver->ops.get_device(hdriver, num);
}