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
 int /*<<< orphan*/  ClearPageHWPoison (struct page*) ; 
 int compound_trans_order (struct page*) ; 

__attribute__((used)) static void clear_page_hwpoison_huge_page(struct page *hpage)
{
	int i;
	int nr_pages = 1 << compound_trans_order(hpage);
	for (i = 0; i < nr_pages; i++)
		ClearPageHWPoison(hpage + i);
}