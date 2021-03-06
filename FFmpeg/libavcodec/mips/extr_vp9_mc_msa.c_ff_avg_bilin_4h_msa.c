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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  ptrdiff_t ;
typedef  int /*<<< orphan*/  int8_t ;

/* Variables and functions */
 int /*<<< orphan*/  common_hz_2t_and_aver_dst_4x4_msa (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  common_hz_2t_and_aver_dst_4x8_msa (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ ** vp9_bilinear_filters_msa ; 

void ff_avg_bilin_4h_msa(uint8_t *dst, ptrdiff_t dst_stride,
                         const uint8_t *src, ptrdiff_t src_stride,
                         int height, int mx, int my)
{
    const int8_t *filter = vp9_bilinear_filters_msa[mx - 1];

    if (4 == height) {
        common_hz_2t_and_aver_dst_4x4_msa(src, src_stride, dst, dst_stride,
                                          filter);
    } else if (8 == height) {
        common_hz_2t_and_aver_dst_4x8_msa(src, src_stride, dst, dst_stride,
                                          filter);
    }
}