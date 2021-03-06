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
struct lpi2c_imx_struct {scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ LPI2C_MIER ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static void lpi2c_imx_intctrl(struct lpi2c_imx_struct *lpi2c_imx,
			      unsigned int enable)
{
	writel(enable, lpi2c_imx->base + LPI2C_MIER);
}