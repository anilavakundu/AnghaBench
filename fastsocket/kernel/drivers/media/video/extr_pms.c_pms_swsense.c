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
 scalar_t__ PHILIPS1 ; 
 scalar_t__ PHILIPS2 ; 
 scalar_t__ decoder ; 
 int /*<<< orphan*/  pms_i2c_write (int,int,short) ; 

__attribute__((used)) static void pms_swsense(short sense)
{
	if(decoder==PHILIPS2)
	{
		pms_i2c_write(0x8A, 0x0A, sense);
		pms_i2c_write(0x8A, 0x0B, sense);
	}
	else if(decoder==PHILIPS1)
	{
		pms_i2c_write(0x42, 0x0A, sense);
		pms_i2c_write(0x42, 0x0B, sense);
	}
}