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
struct TYPE_2__ {int /*<<< orphan*/  (* redo ) () ;} ;

/* Variables and functions */
 TYPE_1__* cont ; 
 int /*<<< orphan*/  generic_success () ; 
 int /*<<< orphan*/  stub1 () ; 

__attribute__((used)) static void success_and_wakeup(void)
{
	generic_success();
	cont->redo();
}