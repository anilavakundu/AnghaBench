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
struct bcm2835_audio_info {int /*<<< orphan*/  worker_cv; int /*<<< orphan*/  flags_pending; } ;

/* Variables and functions */
 int /*<<< orphan*/  AUDIO_PARAMS ; 
 int /*<<< orphan*/  BCM2835_AUDIO_LOCKED (struct bcm2835_audio_info*) ; 
 int /*<<< orphan*/  cv_signal (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
bcm2835_worker_update_params(struct bcm2835_audio_info *sc)
{

	BCM2835_AUDIO_LOCKED(sc);

	sc->flags_pending |= AUDIO_PARAMS;
	cv_signal(&sc->worker_cv);
}