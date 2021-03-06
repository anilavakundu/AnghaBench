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
struct radeon_device {scalar_t__ is_atom_bios; } ;

/* Variables and functions */
 int /*<<< orphan*/  radeon_atombios_i2c_init (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_combios_i2c_init (struct radeon_device*) ; 

void radeon_i2c_init(struct radeon_device *rdev)
{
	if (rdev->is_atom_bios)
		radeon_atombios_i2c_init(rdev);
	else
		radeon_combios_i2c_init(rdev);
}