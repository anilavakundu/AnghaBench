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
typedef  int /*<<< orphan*/  vm_offset_t ;
typedef  int /*<<< orphan*/  video_adapter_t ;
typedef  int /*<<< orphan*/  u_int32_t ;

/* Variables and functions */
 int ENODEV ; 

__attribute__((used)) static int
creator_putp(video_adapter_t *adp, vm_offset_t off, u_int32_t p, u_int32_t a,
    int size, int bpp, int bit_ltor, int byte_ltor)
{

	return (ENODEV);
}