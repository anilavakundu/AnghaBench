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
typedef  int /*<<< orphan*/  ib_portid_t ;

/* Variables and functions */
 int /*<<< orphan*/  IB_GSI_PORT_XMIT_CON_CTRL ; 
 int /*<<< orphan*/  common_func (int /*<<< orphan*/ *,int,int,int,int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mad_dump_perfcounters_xmit_con_ctrl ; 
 scalar_t__ reset ; 
 scalar_t__ reset_only ; 

__attribute__((used)) static void xmitcc_query(ib_portid_t * portid, int port, int mask)
{
	common_func(portid, port, mask, !reset_only, (reset_only || reset),
		    "PortXmitConCtrl", IB_GSI_PORT_XMIT_CON_CTRL,
		    mad_dump_perfcounters_xmit_con_ctrl);
}