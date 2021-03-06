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
typedef  int /*<<< orphan*/  u32 ;
struct i915_hw_context {int dummy; } ;
struct drm_i915_file_private {int /*<<< orphan*/  context_idr; } ;

/* Variables and functions */
 scalar_t__ idr_find (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct i915_hw_context *
i915_gem_context_get(struct drm_i915_file_private *file_priv, u32 id)
{
	return (struct i915_hw_context *)idr_find(&file_priv->context_idr, id);
}