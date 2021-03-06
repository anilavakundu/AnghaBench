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
typedef  scalar_t__ u32 ;

/* Variables and functions */

__attribute__((used)) static inline u32 transport_get_sectors_16(unsigned char *cdb)
{
	return (u32)(cdb[10] << 24) + (cdb[11] << 16) +
		    (cdb[12] << 8) + cdb[13];
}