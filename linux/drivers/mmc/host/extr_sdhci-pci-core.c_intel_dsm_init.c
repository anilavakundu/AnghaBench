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
struct mmc_host {int dummy; } ;
struct intel_host {int d3_retune; int dsm_fns; int /*<<< orphan*/  drv_strength; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  INTEL_DSM_D3_RETUNE ; 
 int /*<<< orphan*/  INTEL_DSM_DRV_STRENGTH ; 
 int /*<<< orphan*/  INTEL_DSM_FNS ; 
 int __intel_dsm (struct intel_host*,struct device*,int /*<<< orphan*/ ,int*) ; 
 int intel_dsm (struct intel_host*,struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mmc_hostname (struct mmc_host*) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void intel_dsm_init(struct intel_host *intel_host, struct device *dev,
			   struct mmc_host *mmc)
{
	int err;
	u32 val;

	intel_host->d3_retune = true;

	err = __intel_dsm(intel_host, dev, INTEL_DSM_FNS, &intel_host->dsm_fns);
	if (err) {
		pr_debug("%s: DSM not supported, error %d\n",
			 mmc_hostname(mmc), err);
		return;
	}

	pr_debug("%s: DSM function mask %#x\n",
		 mmc_hostname(mmc), intel_host->dsm_fns);

	err = intel_dsm(intel_host, dev, INTEL_DSM_DRV_STRENGTH, &val);
	intel_host->drv_strength = err ? 0 : val;

	err = intel_dsm(intel_host, dev, INTEL_DSM_D3_RETUNE, &val);
	intel_host->d3_retune = err ? true : !!val;
}