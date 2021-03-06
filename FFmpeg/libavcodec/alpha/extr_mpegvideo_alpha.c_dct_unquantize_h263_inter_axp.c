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
typedef  int /*<<< orphan*/  int16_t ;
struct TYPE_4__ {int* raster_end; } ;
struct TYPE_5__ {size_t* block_last_index; TYPE_1__ inter_scantable; } ;
typedef  TYPE_2__ MpegEncContext ;

/* Variables and functions */
 int /*<<< orphan*/  dct_unquantize_h263_axp (int /*<<< orphan*/ *,int,int,int) ; 

__attribute__((used)) static void dct_unquantize_h263_inter_axp(MpegEncContext *s, int16_t *block,
                                    int n, int qscale)
{
    int n_coeffs = s->inter_scantable.raster_end[s->block_last_index[n]];
    dct_unquantize_h263_axp(block, n_coeffs, qscale, (qscale - 1) | 1);
}