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
struct TYPE_3__ {int /*<<< orphan*/  t_defattr; int /*<<< orphan*/  t_saved_curattr; int /*<<< orphan*/  t_curattr; } ;
typedef  TYPE_1__ teken_t ;
typedef  int /*<<< orphan*/  teken_attr_t ;

/* Variables and functions */

void
teken_set_defattr(teken_t *t, const teken_attr_t *a)
{

	t->t_curattr = t->t_saved_curattr = t->t_defattr = *a;
}