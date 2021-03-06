#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct bfa_iocfc_s {TYPE_2__* bfa; } ;
struct TYPE_4__ {int /*<<< orphan*/  init_hcb_qe; int /*<<< orphan*/  op_status; } ;
struct TYPE_5__ {TYPE_1__ iocfc; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_STATUS_OK ; 
 int /*<<< orphan*/  bfa_cb_queue (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  bfa_iocfc_init_cb ; 

__attribute__((used)) static void
bfa_iocfc_sm_init_cfg_done_entry(struct bfa_iocfc_s *iocfc)
{
	iocfc->bfa->iocfc.op_status = BFA_STATUS_OK;
	bfa_cb_queue(iocfc->bfa, &iocfc->bfa->iocfc.init_hcb_qe,
		     bfa_iocfc_init_cb, iocfc->bfa);
}