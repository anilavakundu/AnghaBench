#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VC_MEM_SIZE_T ;
typedef  TYPE_1__* VC_MEM_ACCESS_HANDLE_T ;
struct TYPE_3__ {int /*<<< orphan*/  vcMemSize; } ;

/* Variables and functions */

VC_MEM_SIZE_T GetVideoCoreMemorySize( VC_MEM_ACCESS_HANDLE_T vcHandle )
{
    return vcHandle->vcMemSize;
}