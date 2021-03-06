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
struct TYPE_3__ {int /*<<< orphan*/  cr_ticks; int /*<<< orphan*/  cr_rate; } ;
struct TYPE_4__ {TYPE_1__ cr; } ;

/* Variables and functions */
 int BANDLIM_MAX ; 
 int /*<<< orphan*/  M_WAITOK ; 
 TYPE_2__* V_icmp_rates ; 
 int /*<<< orphan*/  counter_u64_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ticks ; 

__attribute__((used)) static void
icmp_bandlimit_init(void)
{

	for (int i = 0; i < BANDLIM_MAX; i++) {
		V_icmp_rates[i].cr.cr_rate = counter_u64_alloc(M_WAITOK);
		V_icmp_rates[i].cr.cr_ticks = ticks;
	}
}