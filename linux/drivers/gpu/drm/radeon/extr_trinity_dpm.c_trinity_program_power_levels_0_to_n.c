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
typedef  size_t u32 ;
struct trinity_ps {int num_levels; int /*<<< orphan*/ * levels; } ;
struct radeon_ps {int dummy; } ;
struct radeon_device {int dummy; } ;

/* Variables and functions */
 struct trinity_ps* trinity_get_ps (struct radeon_ps*) ; 
 int /*<<< orphan*/  trinity_power_level_enable_disable (struct radeon_device*,size_t,int) ; 
 int /*<<< orphan*/  trinity_program_power_level (struct radeon_device*,int /*<<< orphan*/ *,size_t) ; 

__attribute__((used)) static void trinity_program_power_levels_0_to_n(struct radeon_device *rdev,
						struct radeon_ps *new_rps,
						struct radeon_ps *old_rps)
{
	struct trinity_ps *new_ps = trinity_get_ps(new_rps);
	struct trinity_ps *old_ps = trinity_get_ps(old_rps);
	u32 i;
	u32 n_current_state_levels = (old_ps == NULL) ? 1 : old_ps->num_levels;

	for (i = 0; i < new_ps->num_levels; i++) {
		trinity_program_power_level(rdev, &new_ps->levels[i], i);
		trinity_power_level_enable_disable(rdev, i, true);
	}

	for (i = new_ps->num_levels; i < n_current_state_levels; i++)
		trinity_power_level_enable_disable(rdev, i, false);
}