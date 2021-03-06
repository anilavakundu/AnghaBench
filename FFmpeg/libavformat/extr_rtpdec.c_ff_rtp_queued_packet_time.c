#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  int64_t ;
struct TYPE_5__ {TYPE_1__* queue; } ;
struct TYPE_4__ {int /*<<< orphan*/  recvtime; } ;
typedef  TYPE_2__ RTPDemuxContext ;

/* Variables and functions */

int64_t ff_rtp_queued_packet_time(RTPDemuxContext *s)
{
    return s->queue ? s->queue->recvtime : 0;
}