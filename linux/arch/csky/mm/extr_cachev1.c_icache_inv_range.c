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

/* Variables and functions */
 int CACHE_INV ; 
 int INS_CACHE ; 
 int /*<<< orphan*/  cache_op_range (unsigned long,unsigned long,int,int /*<<< orphan*/ ) ; 

void icache_inv_range(unsigned long start, unsigned long end)
{
	cache_op_range(start, end, INS_CACHE|CACHE_INV, 0);
}