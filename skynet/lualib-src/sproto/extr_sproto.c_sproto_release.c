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
struct sproto {int /*<<< orphan*/  memory; } ;

/* Variables and functions */
 int /*<<< orphan*/  pool_release (int /*<<< orphan*/ *) ; 

void
sproto_release(struct sproto * s) {
	if (s == NULL)
		return;
	pool_release(&s->memory);
}