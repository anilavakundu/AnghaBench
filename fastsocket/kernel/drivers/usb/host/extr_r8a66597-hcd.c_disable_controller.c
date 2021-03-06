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
struct r8a66597 {int max_root_hub; } ;

/* Variables and functions */
 int /*<<< orphan*/  INTENB0 ; 
 int /*<<< orphan*/  INTSTS0 ; 
 int /*<<< orphan*/  r8a66597_clock_disable (struct r8a66597*) ; 
 int /*<<< orphan*/  r8a66597_disable_port (struct r8a66597*,int) ; 
 int /*<<< orphan*/  r8a66597_write (struct r8a66597*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void disable_controller(struct r8a66597 *r8a66597)
{
	int port;

	r8a66597_write(r8a66597, 0, INTENB0);
	r8a66597_write(r8a66597, 0, INTSTS0);

	for (port = 0; port < r8a66597->max_root_hub; port++)
		r8a66597_disable_port(r8a66597, port);

	r8a66597_clock_disable(r8a66597);
}