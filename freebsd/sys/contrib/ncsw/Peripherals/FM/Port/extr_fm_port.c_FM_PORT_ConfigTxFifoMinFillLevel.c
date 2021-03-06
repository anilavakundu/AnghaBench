#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
typedef  scalar_t__ t_Handle ;
struct TYPE_4__ {int /*<<< orphan*/  tx_fifo_min_level; } ;
struct TYPE_5__ {scalar_t__ portType; TYPE_1__ dfltCfg; struct TYPE_5__* p_FmPortDriverParam; } ;
typedef  TYPE_2__ t_FmPort ;
typedef  int /*<<< orphan*/  t_Error ;

/* Variables and functions */
 int /*<<< orphan*/  E_INVALID_HANDLE ; 
 int /*<<< orphan*/  E_INVALID_OPERATION ; 
 int /*<<< orphan*/  E_OK ; 
 int /*<<< orphan*/  MAJOR ; 
 int /*<<< orphan*/  RETURN_ERROR (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  SANITY_CHECK_RETURN_ERROR (TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ e_FM_PORT_TYPE_TX ; 
 scalar_t__ e_FM_PORT_TYPE_TX_10G ; 

t_Error FM_PORT_ConfigTxFifoMinFillLevel(t_Handle h_FmPort,
                                         uint32_t minFillLevel)
{
    t_FmPort *p_FmPort = (t_FmPort*)h_FmPort;

    SANITY_CHECK_RETURN_ERROR(p_FmPort, E_INVALID_HANDLE);
    SANITY_CHECK_RETURN_ERROR(p_FmPort->p_FmPortDriverParam, E_INVALID_HANDLE);
    if ((p_FmPort->portType != e_FM_PORT_TYPE_TX_10G)
            && (p_FmPort->portType != e_FM_PORT_TYPE_TX))
        RETURN_ERROR(MAJOR, E_INVALID_OPERATION,
                     ("available for Tx ports only"));

    p_FmPort->p_FmPortDriverParam->dfltCfg.tx_fifo_min_level = minFillLevel;

    return E_OK;
}