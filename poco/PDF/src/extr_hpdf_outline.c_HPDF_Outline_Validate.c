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
struct TYPE_4__ {int obj_class; } ;
struct TYPE_5__ {TYPE_1__ header; } ;
typedef  TYPE_2__* HPDF_Outline ;
typedef  int /*<<< orphan*/  HPDF_BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  HPDF_FALSE ; 
 int HPDF_OCLASS_DICT ; 
 int HPDF_OSUBCLASS_OUTLINE ; 
 int /*<<< orphan*/  HPDF_PTRACE (char*) ; 
 int /*<<< orphan*/  HPDF_TRUE ; 

HPDF_BOOL
HPDF_Outline_Validate (HPDF_Outline  outline)
{
    if (!outline)
        return HPDF_FALSE;

    HPDF_PTRACE((" HPDF_Outline_Validate\n"));

    if (outline->header.obj_class !=
                (HPDF_OSUBCLASS_OUTLINE | HPDF_OCLASS_DICT))
        return HPDF_FALSE;

    return HPDF_TRUE;
}