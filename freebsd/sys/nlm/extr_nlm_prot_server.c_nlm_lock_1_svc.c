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
struct svc_req {int dummy; } ;
struct nlm_lockargs {int /*<<< orphan*/  state; int /*<<< orphan*/  reclaim; int /*<<< orphan*/  alock; int /*<<< orphan*/  exclusive; int /*<<< orphan*/  block; int /*<<< orphan*/  cookie; } ;
typedef  int /*<<< orphan*/  nlm_res ;
typedef  int /*<<< orphan*/  nlm4_res ;
struct TYPE_3__ {int /*<<< orphan*/  state; int /*<<< orphan*/  reclaim; int /*<<< orphan*/  alock; int /*<<< orphan*/  exclusive; int /*<<< orphan*/  block; int /*<<< orphan*/  cookie; } ;
typedef  TYPE_1__ nlm4_lockargs ;
typedef  scalar_t__ bool_t ;

/* Variables and functions */
 scalar_t__ nlm4_lock_4_svc (TYPE_1__*,int /*<<< orphan*/ *,struct svc_req*) ; 
 int /*<<< orphan*/  nlm_convert_to_nlm4_lock (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nlm_convert_to_nlm_res (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

bool_t
nlm_lock_1_svc(struct nlm_lockargs *argp, nlm_res *result, struct svc_req *rqstp)
{
	bool_t retval;
	nlm4_lockargs args4;
	nlm4_res res4;

	args4.cookie = argp->cookie;
	args4.block = argp->block;
	args4.exclusive = argp->exclusive;
	nlm_convert_to_nlm4_lock(&args4.alock, &argp->alock);
	args4.reclaim = argp->reclaim;
	args4.state = argp->state;

	retval = nlm4_lock_4_svc(&args4, &res4, rqstp);
	if (retval)
		nlm_convert_to_nlm_res(result, &res4);

	return (retval);
}