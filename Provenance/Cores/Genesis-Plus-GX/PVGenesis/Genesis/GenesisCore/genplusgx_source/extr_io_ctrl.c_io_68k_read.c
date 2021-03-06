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
struct TYPE_2__ {unsigned int (* data_r ) () ;} ;

/* Variables and functions */
 int* io_reg ; 
 TYPE_1__* port ; 
 unsigned int stub1 () ; 

unsigned int io_68k_read(unsigned int offset)
{
  switch(offset)
  {
    case 0x01:  /* Port A Data */
    case 0x02:  /* Port B Data */
    case 0x03:  /* Port C Data */
    {
      unsigned int mask = 0x80 | io_reg[offset + 3];
      unsigned int data = port[offset-1].data_r();
      return (io_reg[offset] & mask) | (data & ~mask);
    }

    default:  /* return register value */
    {
      return io_reg[offset];
    }
  }
}