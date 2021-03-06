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
struct page {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  PageHuge (struct page*) ; 
 int /*<<< orphan*/  PageLRU (struct page*) ; 
 int __get_any_page (struct page*,unsigned long,int) ; 
 int /*<<< orphan*/  pr_info (char*,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_page (struct page*) ; 
 int /*<<< orphan*/  shake_page (struct page*,int) ; 

__attribute__((used)) static int get_any_page(struct page *page, unsigned long pfn, int flags)
{
	int ret = __get_any_page(page, pfn, flags);

	if (ret == 1 && !PageHuge(page) && !PageLRU(page)) {
		/*
		 * Try to free it.
		 */
		put_page(page);
		shake_page(page, 1);

		/*
		 * Did it turn free?
		 */
		ret = __get_any_page(page, pfn, 0);
		if (!PageLRU(page)) {
			pr_info("soft_offline: %#lx: unknown non LRU page type %lx\n",
				pfn, page->flags);
			return -EIO;
		}
	}
	return ret;
}