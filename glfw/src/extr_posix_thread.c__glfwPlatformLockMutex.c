#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ allocated; int /*<<< orphan*/  handle; } ;
struct TYPE_5__ {TYPE_1__ posix; } ;
typedef  TYPE_2__ _GLFWmutex ;

/* Variables and functions */
 scalar_t__ GLFW_TRUE ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 

void _glfwPlatformLockMutex(_GLFWmutex* mutex)
{
    assert(mutex->posix.allocated == GLFW_TRUE);
    pthread_mutex_lock(&mutex->posix.handle);
}