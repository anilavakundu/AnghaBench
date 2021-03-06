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
typedef  int /*<<< orphan*/  WRes ;
typedef  int /*<<< orphan*/  LONG ;
typedef  int /*<<< orphan*/  CSemaphore ;

/* Variables and functions */
 int /*<<< orphan*/  BOOLToWRes (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseSemaphore (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static WRes Semaphore_Release(CSemaphore *p, LONG releaseCount, LONG *previousCount)
  { return BOOLToWRes(ReleaseSemaphore(*p, releaseCount, previousCount)); }