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
typedef  int u32 ;
struct i2c_adapter {int dummy; } ;

/* Variables and functions */
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_FUNC_SMBUS_READ_BYTE ; 
 int I2C_FUNC_SMBUS_READ_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE_DATA ; 

__attribute__((used)) static u32 saa7146_i2c_func(struct i2c_adapter *adapter)
{
//fm	DEB_I2C(("'%s'.\n", adapter->name));

	return	  I2C_FUNC_I2C
		| I2C_FUNC_SMBUS_QUICK
		| I2C_FUNC_SMBUS_READ_BYTE	| I2C_FUNC_SMBUS_WRITE_BYTE
		| I2C_FUNC_SMBUS_READ_BYTE_DATA | I2C_FUNC_SMBUS_WRITE_BYTE_DATA;
}