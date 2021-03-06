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

/* Variables and functions */
 int SLEEPQ_SLEEP ; 
 int SLEEPQ_UNFAIR ; 
 int /*<<< orphan*/  kick_proc0 () ; 
 int /*<<< orphan*/  sleepq_lock (void*) ; 
 int /*<<< orphan*/  sleepq_release (void*) ; 
 int sleepq_signal (void*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
wakeup_any(void *ident)
{
	int wakeup_swapper;

	sleepq_lock(ident);
	wakeup_swapper = sleepq_signal(ident, SLEEPQ_SLEEP | SLEEPQ_UNFAIR,
	    0, 0);
	sleepq_release(ident);
	if (wakeup_swapper)
		kick_proc0();
}