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
struct drm_device {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int tda998x_encoder_init (struct device*,struct drm_device*) ; 

__attribute__((used)) static int tda998x_bind(struct device *dev, struct device *master, void *data)
{
	struct drm_device *drm = data;

	return tda998x_encoder_init(dev, drm);
}