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
struct throtl_grp {int /*<<< orphan*/  pd; } ;
struct blkcg_gq {int dummy; } ;

/* Variables and functions */
 struct blkcg_gq* pd_to_blkg (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline struct blkcg_gq *tg_to_blkg(struct throtl_grp *tg)
{
	return pd_to_blkg(&tg->pd);
}