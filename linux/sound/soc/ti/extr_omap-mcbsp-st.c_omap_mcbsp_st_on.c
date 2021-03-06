#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct omap_mcbsp {TYPE_2__* st_data; TYPE_1__* pdata; } ;
struct TYPE_4__ {int /*<<< orphan*/  mcbsp_iclk; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* force_ick_on ) (int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 unsigned int MCBSP_READ (struct omap_mcbsp*,int /*<<< orphan*/ ) ; 
 unsigned int MCBSP_ST_READ (struct omap_mcbsp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MCBSP_ST_WRITE (struct omap_mcbsp*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  MCBSP_WRITE (struct omap_mcbsp*,int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int SIDETONEEN ; 
 int /*<<< orphan*/  SSELCR ; 
 unsigned int ST_AUTOIDLE ; 
 unsigned int ST_SIDETONEEN ; 
 int /*<<< orphan*/  SYSCONFIG ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void omap_mcbsp_st_on(struct omap_mcbsp *mcbsp)
{
	unsigned int w;

	if (mcbsp->pdata->force_ick_on)
		mcbsp->pdata->force_ick_on(mcbsp->st_data->mcbsp_iclk, true);

	/* Disable Sidetone clock auto-gating for normal operation */
	w = MCBSP_ST_READ(mcbsp, SYSCONFIG);
	MCBSP_ST_WRITE(mcbsp, SYSCONFIG, w & ~(ST_AUTOIDLE));

	/* Enable McBSP Sidetone */
	w = MCBSP_READ(mcbsp, SSELCR);
	MCBSP_WRITE(mcbsp, SSELCR, w | SIDETONEEN);

	/* Enable Sidetone from Sidetone Core */
	w = MCBSP_ST_READ(mcbsp, SSELCR);
	MCBSP_ST_WRITE(mcbsp, SSELCR, w | ST_SIDETONEEN);
}