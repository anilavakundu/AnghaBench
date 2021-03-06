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
struct c4iw_qp {int /*<<< orphan*/  wq; } ;

/* Variables and functions */
 int /*<<< orphan*/  t4_enable_wq_db (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int enable_qp_db(int id, void *p, void *data)
{
	struct c4iw_qp *qp = p;

	t4_enable_wq_db(&qp->wq);
	return 0;
}