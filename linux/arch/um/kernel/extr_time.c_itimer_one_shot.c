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
struct clock_event_device {int dummy; } ;

/* Variables and functions */
 int itimer_next_event (int /*<<< orphan*/ ,struct clock_event_device*) ; 

__attribute__((used)) static int itimer_one_shot(struct clock_event_device *evt)
{
	return itimer_next_event(0, evt);
}