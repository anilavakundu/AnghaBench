#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  cmsUInt8Number ;
typedef  int cmsUInt32Number ;
typedef  int /*<<< orphan*/  cmsUInt16Number ;
typedef  void* cmsFloat64Number ;
typedef  int /*<<< orphan*/  cmsContext ;
struct TYPE_5__ {void* Z; void* Y; void* X; } ;
typedef  TYPE_1__ cmsCIEXYZ ;
struct TYPE_6__ {int /*<<< orphan*/  InputFormat; } ;
typedef  TYPE_2__ _cmsTRANSFORM ;

/* Variables and functions */
 int T_EXTRA (int /*<<< orphan*/ ) ; 
 scalar_t__ T_PLANAR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cmsFloat2XYZEncoded (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_1__*) ; 

__attribute__((used)) static
cmsUInt8Number* UnrollXYZDoubleTo16(cmsContext ContextID, register _cmsTRANSFORM* info,
                                    register cmsUInt16Number wIn[],
                                    register cmsUInt8Number* accum,
                                    register cmsUInt32Number Stride)
{
    if (T_PLANAR(info -> InputFormat)) {

        cmsCIEXYZ XYZ;
        cmsUInt8Number* pos_X;
        cmsUInt8Number* pos_Y;
        cmsUInt8Number* pos_Z;

        pos_X = accum;
        pos_Y = accum + Stride;
        pos_Z = accum + Stride * 2;

        XYZ.X = *(cmsFloat64Number*)pos_X;
        XYZ.Y = *(cmsFloat64Number*)pos_Y;
        XYZ.Z = *(cmsFloat64Number*)pos_Z;

        cmsFloat2XYZEncoded(ContextID, wIn, &XYZ);

        return accum + sizeof(cmsFloat64Number);

    }

    else {
        cmsFloat2XYZEncoded(ContextID, wIn, (cmsCIEXYZ*) accum);
        accum += sizeof(cmsCIEXYZ) + T_EXTRA(info ->InputFormat) * sizeof(cmsFloat64Number);

        return accum;
    }
}