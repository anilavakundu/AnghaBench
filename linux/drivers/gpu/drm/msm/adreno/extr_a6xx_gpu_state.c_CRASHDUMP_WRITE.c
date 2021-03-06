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
typedef  int u64 ;
typedef  int u32 ;

/* Variables and functions */

__attribute__((used)) static inline int CRASHDUMP_WRITE(u64 *in, u32 reg, u32 val)
{
	in[0] = val;
	in[1] = (((u64) reg) << 44 | (1 << 21) | 1);

	return 2;
}