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
typedef  enum dc_color_space { ____Placeholder_dc_color_space } dc_color_space ;

/* Variables and functions */
 int COLOR_SPACE_XV_YCC_709 ; 
 int COLOR_SPACE_YCBCR709 ; 

__attribute__((used)) static bool is_ycbcr709_type(
		enum dc_color_space color_space)
{
	bool ret = false;

	if (color_space == COLOR_SPACE_YCBCR709	||
		color_space == COLOR_SPACE_XV_YCC_709)
		ret = true;
	return ret;
}