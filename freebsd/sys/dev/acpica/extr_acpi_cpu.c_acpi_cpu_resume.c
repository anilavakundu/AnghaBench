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
 int bus_generic_resume (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_idle (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
acpi_cpu_resume(device_t dev)
{

    enable_idle(device_get_softc(dev));
    return (bus_generic_resume(dev));
}