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
struct lio_droq {int /*<<< orphan*/  pkts_pending; scalar_t__ refill_count; scalar_t__ refill_idx; scalar_t__ read_idx; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_store_rel_int (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
lio_droq_reset_indices(struct lio_droq *droq)
{

	droq->read_idx = 0;
	droq->refill_idx = 0;
	droq->refill_count = 0;
	atomic_store_rel_int(&droq->pkts_pending, 0);
}