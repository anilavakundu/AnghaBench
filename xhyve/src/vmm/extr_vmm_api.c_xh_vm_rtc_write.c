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
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  vm ; 
 int vrtc_nvram_write (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

int
xh_vm_rtc_write(int offset, uint8_t value)
{
	return (vrtc_nvram_write(vm, offset, value));
}