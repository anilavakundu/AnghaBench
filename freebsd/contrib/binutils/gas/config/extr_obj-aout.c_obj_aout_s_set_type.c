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
typedef  int /*<<< orphan*/  symbolS ;
struct TYPE_2__ {int type; } ;

/* Variables and functions */
 TYPE_1__* aout_symbol (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  symbol_get_bfdsym (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
obj_aout_s_set_type (symbolS *sym, int t)
{
  aout_symbol (symbol_get_bfdsym (sym))->type = t;
}