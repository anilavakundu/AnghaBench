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
struct hostapd_data {int /*<<< orphan*/ * sock_ndisc; } ;

/* Variables and functions */
 int /*<<< orphan*/  l2_packet_deinit (int /*<<< orphan*/ *) ; 

void ndisc_snoop_deinit(struct hostapd_data *hapd)
{
	l2_packet_deinit(hapd->sock_ndisc);
	hapd->sock_ndisc = NULL;
}