#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* delays; } ;
struct TYPE_3__ {int /*<<< orphan*/  thrashing_count; int /*<<< orphan*/  thrashing_delay; int /*<<< orphan*/  thrashing_start; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 TYPE_2__* current ; 
 int /*<<< orphan*/  delayacct_end (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void __delayacct_thrashing_end(void)
{
	delayacct_end(&current->delays->lock,
		      &current->delays->thrashing_start,
		      &current->delays->thrashing_delay,
		      &current->delays->thrashing_count);
}