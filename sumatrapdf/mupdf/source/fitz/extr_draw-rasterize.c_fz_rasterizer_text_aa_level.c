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
typedef  int /*<<< orphan*/  fz_rasterizer ;

/* Variables and functions */
 int fz_rasterizer_aa_text_bits (int /*<<< orphan*/ *) ; 

int
fz_rasterizer_text_aa_level(fz_rasterizer *ras)
{
	return fz_rasterizer_aa_text_bits(ras);
}