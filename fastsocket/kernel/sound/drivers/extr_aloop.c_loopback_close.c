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
struct snd_pcm_substream {size_t number; size_t stream; TYPE_1__* runtime; struct loopback* private_data; } ;
struct loopback_pcm {int dummy; } ;
struct loopback_cable {int /*<<< orphan*/ ** streams; } ;
struct loopback {int /*<<< orphan*/  cable_lock; struct loopback_cable*** cables; } ;
struct TYPE_2__ {struct loopback_pcm* private_data; } ;

/* Variables and functions */
 int get_cable_index (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  kfree (struct loopback_cable*) ; 
 int /*<<< orphan*/  loopback_timer_stop (struct loopback_pcm*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int loopback_close(struct snd_pcm_substream *substream)
{
	struct loopback *loopback = substream->private_data;
	struct loopback_pcm *dpcm = substream->runtime->private_data;
	struct loopback_cable *cable;
	int dev = get_cable_index(substream);

	loopback_timer_stop(dpcm);
	mutex_lock(&loopback->cable_lock);
	cable = loopback->cables[substream->number][dev];
	if (cable->streams[!substream->stream]) {
		/* other stream is still alive */
		cable->streams[substream->stream] = NULL;
	} else {
		/* free the cable */
		loopback->cables[substream->number][dev] = NULL;
		kfree(cable);
	}
	mutex_unlock(&loopback->cable_lock);
	return 0;
}