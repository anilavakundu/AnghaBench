#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  nButtonSize; int /*<<< orphan*/  hwndSelf; } ;
typedef  TYPE_1__ PAGER_INFO ;
typedef  int /*<<< orphan*/  INT ;

/* Variables and functions */
 int /*<<< orphan*/  PAGER_RecalcSize (TYPE_1__*) ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static INT
PAGER_SetButtonSize (PAGER_INFO* infoPtr, INT iButtonSize)
{
    INT nTemp = infoPtr->nButtonSize;

    infoPtr->nButtonSize = iButtonSize;
    TRACE("[%p] %d\n", infoPtr->hwndSelf, infoPtr->nButtonSize);

    PAGER_RecalcSize(infoPtr);

    return nTemp;
}