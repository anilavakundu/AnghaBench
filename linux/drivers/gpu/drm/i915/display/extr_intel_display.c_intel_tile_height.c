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
struct drm_framebuffer {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 unsigned int intel_tile_size (int /*<<< orphan*/ ) ; 
 unsigned int intel_tile_width_bytes (struct drm_framebuffer const*,int) ; 
 int /*<<< orphan*/  to_i915 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int
intel_tile_height(const struct drm_framebuffer *fb, int color_plane)
{
	return intel_tile_size(to_i915(fb->dev)) /
		intel_tile_width_bytes(fb, color_plane);
}