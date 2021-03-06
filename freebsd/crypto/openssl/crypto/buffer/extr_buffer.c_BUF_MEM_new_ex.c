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
struct TYPE_4__ {unsigned long flags; } ;
typedef  TYPE_1__ BUF_MEM ;

/* Variables and functions */
 TYPE_1__* BUF_MEM_new () ; 

BUF_MEM *BUF_MEM_new_ex(unsigned long flags)
{
    BUF_MEM *ret;

    ret = BUF_MEM_new();
    if (ret != NULL)
        ret->flags = flags;
    return ret;
}