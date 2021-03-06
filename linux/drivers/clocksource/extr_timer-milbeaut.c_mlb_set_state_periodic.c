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
struct TYPE_2__ {int /*<<< orphan*/  period; } ;
struct timer_of {TYPE_1__ of_clk; } ;
struct clock_event_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLB_TIMER_PERIODIC ; 
 int /*<<< orphan*/  mlb_evt_timer_register_count (struct timer_of*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlb_evt_timer_start (struct timer_of*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlb_evt_timer_stop (struct timer_of*) ; 
 struct timer_of* to_timer_of (struct clock_event_device*) ; 

__attribute__((used)) static int mlb_set_state_periodic(struct clock_event_device *clk)
{
	struct timer_of *to = to_timer_of(clk);

	mlb_evt_timer_stop(to);
	mlb_evt_timer_register_count(to, to->of_clk.period);
	mlb_evt_timer_start(to, MLB_TIMER_PERIODIC);
	return 0;
}