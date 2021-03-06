#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/ * b; int /*<<< orphan*/ * g; int /*<<< orphan*/ * r; } ;
typedef  TYPE_1__ cvid_codebook ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  MAKECOLOUR15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cvid_v4_15(unsigned char *frm, unsigned char *limit, int stride, BOOL inverted,
    cvid_codebook *cb0, cvid_codebook *cb1, cvid_codebook *cb2, cvid_codebook *cb3)
{
unsigned short *vptr = (unsigned short *)frm;
int row_inc;
cvid_codebook * cb[] = {cb0,cb1,cb2,cb3};
int x, y;

    if (!inverted)
        row_inc = -stride/2;
    else
        row_inc = stride/2;

    /* fill 4x4 block of pixels with colour values from codebooks */
    for (y = 0; y < 4; y++)
    {
        if (&vptr[y*row_inc] < (unsigned short *)limit) return;
        for (x = 0; x < 4; x++)
            vptr[y*row_inc + x] = MAKECOLOUR15(cb[x/2+(y/2)*2]->r[x%2+(y%2)*2], cb[x/2+(y/2)*2]->g[x%2+(y%2)*2], cb[x/2+(y/2)*2]->b[x%2+(y%2)*2]);
    }
}