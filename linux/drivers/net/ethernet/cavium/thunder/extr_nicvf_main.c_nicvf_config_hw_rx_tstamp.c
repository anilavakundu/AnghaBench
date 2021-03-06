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
struct TYPE_2__ {int enable; int /*<<< orphan*/  msg; } ;
union nic_mbx {TYPE_1__ ptp; } ;
struct nicvf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  NIC_MBOX_MSG_PTP_CFG ; 
 int nicvf_send_msg_to_pf (struct nicvf*,union nic_mbx*) ; 

__attribute__((used)) static int nicvf_config_hw_rx_tstamp(struct nicvf *nic, bool enable)
{
	union nic_mbx mbx = {};

	mbx.ptp.msg = NIC_MBOX_MSG_PTP_CFG;
	mbx.ptp.enable = enable;

	return nicvf_send_msg_to_pf(nic, &mbx);
}