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
struct gigaset_capi_ctr {int /*<<< orphan*/  ctr; } ;
struct cardstate {struct gigaset_capi_ctr* iif; } ;

/* Variables and functions */
 int /*<<< orphan*/  detach_capi_ctr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct gigaset_capi_ctr*) ; 

void gigaset_isdn_unregdev(struct cardstate *cs)
{
	struct gigaset_capi_ctr *iif = cs->iif;

	detach_capi_ctr(&iif->ctr);
	kfree(iif);
	cs->iif = NULL;
}