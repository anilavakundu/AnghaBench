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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  device_add_child (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  device_probe_and_attach (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
lpbb_attach(device_t dev)
{
	device_t bitbang;

	/* add generic bit-banging code */
	bitbang = device_add_child(dev, "iicbb", -1);
	device_probe_and_attach(bitbang);

	return (0);
}