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

/* Variables and functions */
 int /*<<< orphan*/  B0 ; 
 int /*<<< orphan*/  E6 ; 
 int /*<<< orphan*/  E7 ; 
 int /*<<< orphan*/  matrix_init_user () ; 
 int /*<<< orphan*/  setPinOutput (int /*<<< orphan*/ ) ; 

void matrix_init_kb(void) {
    setPinOutput(B0);
    setPinOutput(E6);
    setPinOutput(E7);

    matrix_init_user();
}