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
struct nouveau_bo {int dummy; } ;
struct drm_gem_object {struct nouveau_bo* driver_private; } ;

/* Variables and functions */

__attribute__((used)) static inline struct nouveau_bo *
nouveau_gem_object(struct drm_gem_object *gem)
{
	return gem ? gem->driver_private : NULL;
}