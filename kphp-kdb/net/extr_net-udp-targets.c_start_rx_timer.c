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
struct event_timer {scalar_t__ h_idx; int /*<<< orphan*/  wakeup; scalar_t__ wakeup_time; } ;
struct udp_target {scalar_t__ rx_timeout; struct event_timer rx_timer; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  insert_event_timer (struct event_timer*) ; 
 scalar_t__ precise_now ; 
 int /*<<< orphan*/  rx_gateway ; 

void start_rx_timer (struct udp_target *S) {
  struct event_timer *ev = &S->rx_timer;
  ev->wakeup_time = precise_now + S->rx_timeout;
  ev->wakeup = rx_gateway;
  assert (!ev->h_idx);
  ev->h_idx = 0;
  insert_event_timer (ev);
}