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
typedef  int /*<<< orphan*/  PIRP ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/ * IoGetTopLevelIrp () ; 
 int /*<<< orphan*/  IoSetTopLevelIrp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NTFS ; 
 int /*<<< orphan*/  TRACE_ (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  TRUE ; 

BOOLEAN
NtfsIsIrpTopLevel(PIRP Irp)
{
    BOOLEAN ReturnCode = FALSE;

    TRACE_(NTFS, "NtfsIsIrpTopLevel()\n");

    if (IoGetTopLevelIrp() == NULL)
    {
        IoSetTopLevelIrp(Irp);
        ReturnCode = TRUE;
    }

    return ReturnCode;
}