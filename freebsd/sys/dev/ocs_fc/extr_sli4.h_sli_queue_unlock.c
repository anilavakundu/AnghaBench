#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  lock; } ;
typedef  TYPE_1__ sli4_queue_t ;

/* Variables and functions */
 int /*<<< orphan*/  ocs_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void
sli_queue_unlock(sli4_queue_t *q)
{
	ocs_unlock(&q->lock);
}