#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int dummy; } ;
struct page {int /*<<< orphan*/  flags; } ;
struct TYPE_3__ {scalar_t__ n_aliases; } ;
struct TYPE_4__ {TYPE_1__ dcache; } ;

/* Variables and functions */
 int /*<<< orphan*/  KM_USER0 ; 
 int /*<<< orphan*/  KM_USER1 ; 
 unsigned long PAGE_MASK ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PG_dcache_dirty ; 
 int /*<<< orphan*/  __flush_purge_region (void*,int /*<<< orphan*/ ) ; 
 TYPE_2__ boot_cpu_data ; 
 int /*<<< orphan*/  copy_page (void*,void*) ; 
 void* kmap_atomic (struct page*,int /*<<< orphan*/ ) ; 
 void* kmap_coherent (struct page*,unsigned long) ; 
 int /*<<< orphan*/  kunmap_atomic (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kunmap_coherent (void*) ; 
 scalar_t__ page_mapped (struct page*) ; 
 scalar_t__ pages_do_alias (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  smp_wmb () ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void copy_user_highpage(struct page *to, struct page *from,
			unsigned long vaddr, struct vm_area_struct *vma)
{
	void *vfrom, *vto;

	vto = kmap_atomic(to, KM_USER1);

	if (boot_cpu_data.dcache.n_aliases && page_mapped(from) &&
	    !test_bit(PG_dcache_dirty, &from->flags)) {
		vfrom = kmap_coherent(from, vaddr);
		copy_page(vto, vfrom);
		kunmap_coherent(vfrom);
	} else {
		vfrom = kmap_atomic(from, KM_USER0);
		copy_page(vto, vfrom);
		kunmap_atomic(vfrom, KM_USER0);
	}

	if (pages_do_alias((unsigned long)vto, vaddr & PAGE_MASK))
		__flush_purge_region(vto, PAGE_SIZE);

	kunmap_atomic(vto, KM_USER1);
	/* Make sure this page is cleared on other CPU's too before using it */
	smp_wmb();
}