#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {scalar_t__ probs; } ;
struct TYPE_6__ {int /*<<< orphan*/  (* Free ) (TYPE_1__*,scalar_t__) ;} ;
typedef  TYPE_1__ ISzAlloc ;
typedef  TYPE_2__ CLzmaDec ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (TYPE_1__*,scalar_t__) ; 

void LzmaDec_FreeProbs(CLzmaDec *p, ISzAlloc *alloc)
{
   alloc->Free(alloc, p->probs);
   p->probs = 0;
}