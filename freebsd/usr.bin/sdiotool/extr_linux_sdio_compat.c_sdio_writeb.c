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
typedef  int /*<<< orphan*/  u8 ;
struct sdio_func {int /*<<< orphan*/  num; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int sdio_write_1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 

void sdio_writeb(struct sdio_func *func, u8 b,
		 unsigned int addr, int *err_ret) {
	*err_ret = sdio_write_1(func->dev, func->num, addr, b);
}