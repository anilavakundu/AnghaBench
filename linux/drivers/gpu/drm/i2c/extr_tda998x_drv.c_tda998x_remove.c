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
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  component_del (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tda998x_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tda998x_ops ; 

__attribute__((used)) static int tda998x_remove(struct i2c_client *client)
{
	component_del(&client->dev, &tda998x_ops);
	tda998x_destroy(&client->dev);
	return 0;
}