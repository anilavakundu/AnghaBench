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
struct nouveau_engine {int /*<<< orphan*/  base; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv50_vm_flush_engine (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int
nv84_crypt_tlb_flush(struct nouveau_engine *engine)
{
	nv50_vm_flush_engine(&engine->base, 0x0a);
	return 0;
}