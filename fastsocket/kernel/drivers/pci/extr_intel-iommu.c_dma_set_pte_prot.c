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
struct dma_pte {int val; } ;

/* Variables and functions */

__attribute__((used)) static inline void dma_set_pte_prot(struct dma_pte *pte, unsigned long prot)
{
	pte->val = (pte->val & ~3) | (prot & 3);
}