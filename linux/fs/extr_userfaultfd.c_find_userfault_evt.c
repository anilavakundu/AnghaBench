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
struct userfaultfd_wait_queue {int dummy; } ;
struct userfaultfd_ctx {int /*<<< orphan*/  event_wqh; } ;

/* Variables and functions */
 struct userfaultfd_wait_queue* find_userfault_in (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline struct userfaultfd_wait_queue *find_userfault_evt(
		struct userfaultfd_ctx *ctx)
{
	return find_userfault_in(&ctx->event_wqh);
}