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
struct TYPE_3__ {int /*<<< orphan*/  vmCvar; } ;
typedef  TYPE_1__ cvarTable_t ;

/* Variables and functions */
 TYPE_1__* cvarTable ; 
 int cvarTableSize ; 
 int /*<<< orphan*/  trap_Cvar_Update (int /*<<< orphan*/ ) ; 

void UI_UpdateCvars( void ) {
	int			i;
	cvarTable_t	*cv;

	for ( i = 0, cv = cvarTable ; i < cvarTableSize ; i++, cv++ ) {
		if ( !cv->vmCvar ) {
			continue;
		}

		trap_Cvar_Update( cv->vmCvar );
	}
}