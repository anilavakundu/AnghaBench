#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ count; } ;
struct TYPE_3__ {int (* arswitch_atu_flush ) (struct arswitch_softc*) ;} ;
struct arswitch_softc {TYPE_2__ atu; TYPE_1__ hal; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARSWITCH_LOCK (struct arswitch_softc*) ; 
 int /*<<< orphan*/  ARSWITCH_UNLOCK (struct arswitch_softc*) ; 
 struct arswitch_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int stub1 (struct arswitch_softc*) ; 

__attribute__((used)) static int
arswitch_atu_flush_all(device_t dev)
{
	struct arswitch_softc *sc;
	int err;

	sc = device_get_softc(dev);
	ARSWITCH_LOCK(sc);
	err = sc->hal.arswitch_atu_flush(sc);
	/* Invalidate cached ATU */
	sc->atu.count = 0;
	ARSWITCH_UNLOCK(sc);
	return (err);
}