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
struct r8a66597 {int /*<<< orphan*/  rh_timer; } ;

/* Variables and functions */
 int /*<<< orphan*/  R8A66597_RH_POLL_TIME ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void r8a66597_root_hub_start_polling(struct r8a66597 *r8a66597)
{
	mod_timer(&r8a66597->rh_timer,
			jiffies + msecs_to_jiffies(R8A66597_RH_POLL_TIME));
}