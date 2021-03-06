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
typedef  int /*<<< orphan*/  ulong ;

/* Variables and functions */
 scalar_t__ CCM_BASE ; 
 scalar_t__ CCM_PPCTL ; 
 int /*<<< orphan*/  __raw_readl (scalar_t__) ; 
 unsigned long mxc_decode_pll (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static unsigned long get_rate_ppll(void)
{
	ulong ppctl = __raw_readl(CCM_BASE + CCM_PPCTL);

	return mxc_decode_pll(ppctl, 24000000);
}