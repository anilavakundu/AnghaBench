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
struct TYPE_2__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  subi; } ;

/* Variables and functions */
 int /*<<< orphan*/  init_rand48 () ; 
 long nrand48 (int /*<<< orphan*/ ) ; 
 TYPE_1__ rand48 ; 
 int /*<<< orphan*/  vlc_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_mutex_unlock (int /*<<< orphan*/ *) ; 

long vlc_lrand48 (void)
{
    long ret;

    vlc_mutex_lock (&rand48.lock);
    init_rand48 ();
    ret = nrand48 (rand48.subi);
    vlc_mutex_unlock (&rand48.lock);
    return ret;
}