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
struct timer_list {int dummy; } ;
struct sock {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __sock_put (struct sock*) ; 
 scalar_t__ del_timer (struct timer_list*) ; 
 scalar_t__ timer_pending (struct timer_list*) ; 

void sk_stop_timer(struct sock *sk, struct timer_list* timer)
{
	if (timer_pending(timer) && del_timer(timer))
		__sock_put(sk);
}