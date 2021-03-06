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
struct bsg_job {int /*<<< orphan*/  kref; } ;

/* Variables and functions */
 int /*<<< orphan*/  bsg_teardown_job ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void bsg_job_put(struct bsg_job *job)
{
	kref_put(&job->kref, bsg_teardown_job);
}