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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint16_t ;

/* Variables and functions */
 int /*<<< orphan*/  sldns_read_uint16 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static uint16_t
rrsig_rdata_get_type_covered(uint8_t* rdata, size_t rdatalen)
{
	if(rdatalen < 4)
		return 0;
	return sldns_read_uint16(rdata+2);
}