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
struct comedi_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PORT_PDEBUG (char*,unsigned long,unsigned long) ; 
 unsigned long inl (unsigned long) ; 

__attribute__((used)) static inline unsigned long me4000_inl(struct comedi_device *dev,
				       unsigned long port)
{
	unsigned long value;
	value = inl(port);
	PORT_PDEBUG("<-- 0x%08lX port 0x%04lX\n", value, port);
	return value;
}