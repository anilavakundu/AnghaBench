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
struct TYPE_3__ {scalar_t__ pMemCtx; } ;
typedef  TYPE_1__ lsm_env ;
typedef  int /*<<< orphan*/  TmGlobal ;

/* Variables and functions */
 int /*<<< orphan*/  tmFree (int /*<<< orphan*/ *,void*) ; 

__attribute__((used)) static void tmLsmEnvFree(lsm_env *p, void *ptr){ 
  tmFree((TmGlobal *)(p->pMemCtx), ptr); 
}