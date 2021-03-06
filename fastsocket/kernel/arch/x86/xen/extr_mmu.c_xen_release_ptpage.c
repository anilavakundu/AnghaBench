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
struct page {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ClearPagePinned (struct page*) ; 
 int /*<<< orphan*/  MMUEXT_UNPIN_TABLE ; 
 int /*<<< orphan*/  PFN_PHYS (unsigned long) ; 
 unsigned int PT_PTE ; 
 int /*<<< orphan*/  PageHighMem (struct page*) ; 
 scalar_t__ PagePinned (struct page*) ; 
 scalar_t__ USE_SPLIT_PTLOCKS ; 
 int /*<<< orphan*/  __va (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  make_lowmem_page_readwrite (int /*<<< orphan*/ ) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/  pin_pagetable_pfn (int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static void xen_release_ptpage(unsigned long pfn, unsigned level)
{
	struct page *page = pfn_to_page(pfn);

	if (PagePinned(page)) {
		if (!PageHighMem(page)) {
			if (level == PT_PTE && USE_SPLIT_PTLOCKS)
				pin_pagetable_pfn(MMUEXT_UNPIN_TABLE, pfn);
			make_lowmem_page_readwrite(__va(PFN_PHYS(pfn)));
		}
		ClearPagePinned(page);
	}
}