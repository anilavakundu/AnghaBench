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
typedef  int uint8 ;
typedef  int uint16 ;

/* Variables and functions */

__attribute__((used)) static uint16 getchecksum(uint8 *rom, int length)
{
  int i;
  uint16 checksum = 0;

  for (i = 0; i < length; i += 2)
  {
    checksum += ((rom[i] << 8) + rom[i + 1]);
  }

  return checksum;
}