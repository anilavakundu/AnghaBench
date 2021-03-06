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
struct smu_power_context {scalar_t__ power_context_size; int /*<<< orphan*/ * power_context; } ;
struct smu_context {int /*<<< orphan*/  pm_enabled; struct smu_power_context smu_power; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int smu_v11_0_fini_power(struct smu_context *smu)
{
	struct smu_power_context *smu_power = &smu->smu_power;

	if (!smu->pm_enabled)
		return 0;
	if (!smu_power->power_context || smu_power->power_context_size == 0)
		return -EINVAL;

	kfree(smu_power->power_context);
	smu_power->power_context = NULL;
	smu_power->power_context_size = 0;

	return 0;
}