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
struct srp_target {int /*<<< orphan*/  lock; int /*<<< orphan*/  cmd_queue; } ;
struct iu_entry {int /*<<< orphan*/  ilist; struct srp_target* target; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline void queue_cmd(struct iu_entry *iue)
{
	struct srp_target *target = iue->target;
	unsigned long flags;

	spin_lock_irqsave(&target->lock, flags);
	list_add_tail(&iue->ilist, &target->cmd_queue);
	spin_unlock_irqrestore(&target->lock, flags);
}