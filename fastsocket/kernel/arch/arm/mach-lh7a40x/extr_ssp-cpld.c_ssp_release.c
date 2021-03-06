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
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ssp_chip_select (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ssp_lock ; 

__attribute__((used)) static void ssp_release (void)
{
	ssp_chip_select (0);	/* just in case */
	spin_unlock (&ssp_lock);
}