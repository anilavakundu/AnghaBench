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

/* Variables and functions */
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  EXIT_SUCCESS ; 
 int SIGTERM ; 
 int /*<<< orphan*/  _exit (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void signal_handler(int sig)
{
	if (sig == SIGTERM)
		_exit(EXIT_SUCCESS);

	_exit(EXIT_FAILURE);
}