#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct tps_pmic {int /*<<< orphan*/  io_lock; TYPE_1__* client; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int tps_6507x_read (struct tps_pmic*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tps_6507x_reg_read(struct tps_pmic *tps, u8 reg)
{
	int data;

	mutex_lock(&tps->io_lock);

	data = tps_6507x_read(tps, reg);
	if (data < 0)
		dev_err(&tps->client->dev, "Read from reg 0x%x failed\n", reg);

	mutex_unlock(&tps->io_lock);
	return data;
}