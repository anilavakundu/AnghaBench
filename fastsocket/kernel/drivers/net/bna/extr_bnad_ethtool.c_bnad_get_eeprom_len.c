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
struct net_device {int dummy; } ;

/* Variables and functions */
 int BFA_TOTAL_FLASH_SIZE ; 

__attribute__((used)) static int
bnad_get_eeprom_len(struct net_device *netdev)
{
	return BFA_TOTAL_FLASH_SIZE;
}