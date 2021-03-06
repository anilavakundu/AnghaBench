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
struct sp8870_state {int dummy; } ;

/* Variables and functions */
 int sp8870_writereg (struct sp8870_state*,int,int) ; 

__attribute__((used)) static int sp8870_wake_up(struct sp8870_state* state)
{
	// enable TS output and interface pins
	return sp8870_writereg(state, 0xC18, 0x00D);
}