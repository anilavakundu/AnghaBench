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
struct drm_gem_vram_object {int dummy; } ;
struct drm_gem_object {int dummy; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (void*) ; 
 void* drm_gem_vram_kmap (struct drm_gem_vram_object*,int,int /*<<< orphan*/ *) ; 
 struct drm_gem_vram_object* drm_gem_vram_of_gem (struct drm_gem_object*) ; 
 int drm_gem_vram_pin (struct drm_gem_vram_object*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_gem_vram_unpin (struct drm_gem_vram_object*) ; 

__attribute__((used)) static void *drm_gem_vram_object_vmap(struct drm_gem_object *gem)
{
	struct drm_gem_vram_object *gbo = drm_gem_vram_of_gem(gem);
	int ret;
	void *base;

	ret = drm_gem_vram_pin(gbo, 0);
	if (ret)
		return NULL;
	base = drm_gem_vram_kmap(gbo, true, NULL);
	if (IS_ERR(base)) {
		drm_gem_vram_unpin(gbo);
		return NULL;
	}
	return base;
}