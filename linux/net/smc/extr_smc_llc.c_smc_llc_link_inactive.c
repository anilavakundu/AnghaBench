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
struct smc_link {int /*<<< orphan*/  llc_testlink_wrk; int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  SMC_LNK_INACTIVE ; 
 int /*<<< orphan*/  cancel_delayed_work (int /*<<< orphan*/ *) ; 

void smc_llc_link_inactive(struct smc_link *link)
{
	link->state = SMC_LNK_INACTIVE;
	cancel_delayed_work(&link->llc_testlink_wrk);
}