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
struct expr_status {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  expr; } ;

/* Variables and functions */
 TYPE_1__* cfun ; 
 int /*<<< orphan*/  ggc_alloc_cleared (int) ; 

void
init_expr (void)
{
  cfun->expr = ggc_alloc_cleared (sizeof (struct expr_status));
}