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
struct atmel_sha_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  atmel_sha_handle_queue (struct atmel_sha_dev*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void atmel_sha_queue_task(unsigned long data)
{
	struct atmel_sha_dev *dd = (struct atmel_sha_dev *)data;

	atmel_sha_handle_queue(dd, NULL);
}