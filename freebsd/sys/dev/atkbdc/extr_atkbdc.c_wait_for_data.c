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
struct atkbdc_softc {int retry; } ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KBDC_DELAYTIME ; 
 int /*<<< orphan*/  KBDD_DELAYTIME ; 
 int KBDS_ANY_BUFFER_FULL ; 
 int read_status (struct atkbdc_softc*) ; 

__attribute__((used)) static int
wait_for_data(struct atkbdc_softc *kbdc)
{
    int retry;
    int f;

    /* CPU will stay inside the loop for 200msec at most */
    retry = kbdc->retry * 2;

    while ((f = read_status(kbdc) & KBDS_ANY_BUFFER_FULL) == 0) {
        DELAY(KBDC_DELAYTIME);
        if (--retry < 0)
    	    return 0;
    }
    DELAY(KBDD_DELAYTIME);
    return f;
}