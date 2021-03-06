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
struct hme_sbus_softc {int /*<<< orphan*/  hsc_hme; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct hme_sbus_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hme_resume (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
hme_sbus_resume(device_t dev)
{
	struct hme_sbus_softc *hsc;

	hsc = device_get_softc(dev);
	hme_resume(&hsc->hsc_hme);
	return (0);
}