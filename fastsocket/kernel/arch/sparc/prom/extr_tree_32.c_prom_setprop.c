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
struct TYPE_2__ {int (* no_setprop ) (int,char const*,char*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  prom_lock ; 
 TYPE_1__* prom_nodeops ; 
 int /*<<< orphan*/  restore_current () ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int stub1 (int,char const*,char*,int) ; 

int prom_setprop(int node, const char *pname, char *value, int size)
{
	unsigned long flags;
	int ret;

	if(size == 0) return 0;
	if((pname == 0) || (value == 0)) return 0;
	spin_lock_irqsave(&prom_lock, flags);
	ret = prom_nodeops->no_setprop(node, pname, value, size);
	restore_current();
	spin_unlock_irqrestore(&prom_lock, flags);
	return ret;
}