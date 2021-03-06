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
struct TYPE_5__ {TYPE_1__* obj; } ;
struct TYPE_4__ {int flags; scalar_t__ nid; } ;
typedef  TYPE_2__ ADDED_OBJ ;

/* Variables and functions */
 int ASN1_OBJECT_FLAG_DYNAMIC ; 
 int ASN1_OBJECT_FLAG_DYNAMIC_DATA ; 
 int ASN1_OBJECT_FLAG_DYNAMIC_STRINGS ; 

__attribute__((used)) static void cleanup1_doall(ADDED_OBJ *a)
{
    a->obj->nid = 0;
    a->obj->flags |= ASN1_OBJECT_FLAG_DYNAMIC |
        ASN1_OBJECT_FLAG_DYNAMIC_STRINGS | ASN1_OBJECT_FLAG_DYNAMIC_DATA;
}