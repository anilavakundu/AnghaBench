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
typedef  int /*<<< orphan*/  collelem_t ;

/* Variables and functions */
 int /*<<< orphan*/  T_COLLELEM ; 
 int /*<<< orphan*/ * currelem ; 
 int /*<<< orphan*/  start_order (int /*<<< orphan*/ ) ; 

void
start_order_collelem(collelem_t *e)
{
	start_order(T_COLLELEM);
	currelem = e;
}