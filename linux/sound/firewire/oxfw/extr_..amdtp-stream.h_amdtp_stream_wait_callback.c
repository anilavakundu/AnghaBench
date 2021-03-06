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
struct amdtp_stream {int callbacked; int /*<<< orphan*/  callback_wait; } ;

/* Variables and functions */
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 scalar_t__ wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool amdtp_stream_wait_callback(struct amdtp_stream *s,
					      unsigned int timeout)
{
	return wait_event_timeout(s->callback_wait,
				  s->callbacked == true,
				  msecs_to_jiffies(timeout)) > 0;
}