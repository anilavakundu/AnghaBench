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
struct TYPE_3__ {scalar_t__ bq_size; } ;
typedef  TYPE_1__ bqueue_t ;
typedef  int boolean_t ;

/* Variables and functions */

boolean_t
bqueue_empty(bqueue_t *q)
{
	return (q->bq_size == 0);
}