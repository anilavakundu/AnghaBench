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
typedef  struct mtx* t_Handle ;
struct mtx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_NETCOMMSW ; 
 int /*<<< orphan*/  free (struct mtx*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_destroy (struct mtx*) ; 

void
XX_FreeSpinlock(t_Handle h_Spinlock)
{
	struct mtx *m;

	m = h_Spinlock;

	mtx_destroy(m);
	free(m, M_NETCOMMSW);
}