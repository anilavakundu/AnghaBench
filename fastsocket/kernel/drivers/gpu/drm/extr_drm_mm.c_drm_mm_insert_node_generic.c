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
struct drm_mm_node {int dummy; } ;
struct drm_mm {int dummy; } ;

/* Variables and functions */
 int ENOSPC ; 
 int /*<<< orphan*/  drm_mm_insert_helper (struct drm_mm_node*,struct drm_mm_node*,unsigned long,unsigned int,unsigned long) ; 
 struct drm_mm_node* drm_mm_search_free_generic (struct drm_mm*,unsigned long,unsigned int,unsigned long,int /*<<< orphan*/ ) ; 

int drm_mm_insert_node_generic(struct drm_mm *mm, struct drm_mm_node *node,
			       unsigned long size, unsigned alignment,
			       unsigned long color)
{
	struct drm_mm_node *hole_node;

	hole_node = drm_mm_search_free_generic(mm, size, alignment,
					       color, 0);
	if (!hole_node)
		return -ENOSPC;

	drm_mm_insert_helper(hole_node, node, size, alignment, color);
	return 0;
}