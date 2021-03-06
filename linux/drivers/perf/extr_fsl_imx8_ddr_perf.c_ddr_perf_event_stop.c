#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  config; } ;
struct hw_perf_event {int idx; int /*<<< orphan*/  state; } ;
struct perf_event {TYPE_1__ attr; struct hw_perf_event hw; int /*<<< orphan*/  pmu; } ;
struct ddr_pmu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PERF_HES_STOPPED ; 
 int /*<<< orphan*/  ddr_perf_counter_enable (struct ddr_pmu*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  ddr_perf_event_update (struct perf_event*) ; 
 struct ddr_pmu* to_ddr_pmu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ddr_perf_event_stop(struct perf_event *event, int flags)
{
	struct ddr_pmu *pmu = to_ddr_pmu(event->pmu);
	struct hw_perf_event *hwc = &event->hw;
	int counter = hwc->idx;

	ddr_perf_counter_enable(pmu, event->attr.config, counter, false);
	ddr_perf_event_update(event);

	hwc->state |= PERF_HES_STOPPED;
}