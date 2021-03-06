#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint16_t ;
struct ath_hal {int dummy; } ;
typedef  int /*<<< orphan*/  int16_t ;
struct TYPE_3__ {scalar_t__ channel; } ;
typedef  TYPE_1__ HAL_CHANNEL_INTERNAL ;

/* Variables and functions */

__attribute__((used)) static int16_t
ar5111GetNfAdjust(struct ath_hal *ah, const HAL_CHANNEL_INTERNAL *c)
{
	static const struct {
		uint16_t freqLow;
		int16_t	  adjust;
	} adjust5111[] = {
		{ 5790,	6 },	/* NB: ordered high -> low */
		{ 5730, 4 },
		{ 5690, 3 },
		{ 5660, 2 },
		{ 5610, 1 },
		{ 5530, 0 },
		{ 5450, 0 },
		{ 5379, 1 },
		{ 5209, 3 },
		{ 3000, 5 },
		{    0, 0 },
	};
	int i;

	for (i = 0; c->channel <= adjust5111[i].freqLow; i++)
		;
	return adjust5111[i].adjust;
}