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
struct pbuf {int /*<<< orphan*/  tot_len; } ;
typedef  int /*<<< orphan*/  err_t ;

/* Variables and functions */
 int /*<<< orphan*/  ERROR (char*) ; 
 int /*<<< orphan*/  ERR_MEM ; 
 int /*<<< orphan*/  ERR_OK ; 
 int /*<<< orphan*/  HCI_INFO_PARAM_OGF ; 
 int /*<<< orphan*/  HCI_R_BD_ADDR_OCF ; 
 int /*<<< orphan*/  HCI_R_BD_ADDR_PLEN ; 
 int /*<<< orphan*/  PBUF_RAM ; 
 int /*<<< orphan*/  PBUF_RAW ; 
 struct pbuf* btpbuf_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  btpbuf_free (struct pbuf*) ; 
 struct pbuf* hci_cmd_ass (struct pbuf*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  physbusif_output (struct pbuf*,int /*<<< orphan*/ ) ; 

err_t hci_read_bd_addr(void)
{
	struct pbuf *p = NULL;

	if((p=btpbuf_alloc(PBUF_RAW,HCI_R_BD_ADDR_PLEN,PBUF_RAM))==NULL) {
		ERROR("hci_read_bd_addr: Could not allocate memory for pbuf\n");
		return ERR_MEM;
	}

	p = hci_cmd_ass(p,HCI_R_BD_ADDR_OCF,HCI_INFO_PARAM_OGF,HCI_R_BD_ADDR_PLEN);

	physbusif_output(p,p->tot_len);
	btpbuf_free(p);

	return ERR_OK;
}