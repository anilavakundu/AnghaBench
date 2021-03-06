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
typedef  int /*<<< orphan*/  RTPSession ;

/* Variables and functions */
 int /*<<< orphan*/  LOGGER_DEBUG (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rtp_stop_receiving (int /*<<< orphan*/ *) ; 

void rtp_kill (RTPSession *session)
{
    if (!session)
        return;

    LOGGER_DEBUG("Terminated RTP session: %p", session);

    rtp_stop_receiving (session);
    free (session);
}