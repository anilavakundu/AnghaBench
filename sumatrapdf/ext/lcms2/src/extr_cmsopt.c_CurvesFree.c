#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  size_t cmsUInt32Number ;
typedef  int /*<<< orphan*/  cmsContext ;
struct TYPE_2__ {size_t nCurves; void** Curves; } ;
typedef  TYPE_1__ Curves16Data ;

/* Variables and functions */
 int /*<<< orphan*/  _cmsFree (int /*<<< orphan*/ ,void*) ; 

__attribute__((used)) static
void CurvesFree(cmsContext ContextID, void* ptr)
{
     Curves16Data* Data = (Curves16Data*) ptr;
     cmsUInt32Number i;

     for (i=0; i < Data -> nCurves; i++) {

         _cmsFree(ContextID, Data ->Curves[i]);
     }

     _cmsFree(ContextID, Data ->Curves);
     _cmsFree(ContextID, ptr);
}