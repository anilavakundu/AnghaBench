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
 int R4K_HIT ; 
 int R4K_INDEX ; 
 int /*<<< orphan*/  __local_r4k_flush_icache_range (unsigned long,unsigned long,int,int) ; 

__attribute__((used)) static inline void local_r4k_flush_icache_range(unsigned long start,
						unsigned long end)
{
	__local_r4k_flush_icache_range(start, end, R4K_HIT | R4K_INDEX, false);
}