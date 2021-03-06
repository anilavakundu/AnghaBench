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
typedef  int uint32_t ;
typedef  scalar_t__ uint16_t ;
struct dcn20_dwbc {int dummy; } ;
typedef  enum wbscl_coef_filter_type_sel { ____Placeholder_wbscl_coef_filter_type_sel } wbscl_coef_filter_type_sel ;

/* Variables and functions */
 int NUM_PHASES ; 
 int /*<<< orphan*/  REG_SET_3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_SET_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  WBSCL_COEF_RAM_EVEN_TAP_COEF ; 
 int /*<<< orphan*/  WBSCL_COEF_RAM_EVEN_TAP_COEF_EN ; 
 int /*<<< orphan*/  WBSCL_COEF_RAM_FILTER_TYPE ; 
 int /*<<< orphan*/  WBSCL_COEF_RAM_ODD_TAP_COEF ; 
 int /*<<< orphan*/  WBSCL_COEF_RAM_ODD_TAP_COEF_EN ; 
 int /*<<< orphan*/  WBSCL_COEF_RAM_PHASE ; 
 int /*<<< orphan*/  WBSCL_COEF_RAM_SELECT ; 
 int /*<<< orphan*/  WBSCL_COEF_RAM_TAP_DATA ; 
 int /*<<< orphan*/  WBSCL_COEF_RAM_TAP_PAIR_IDX ; 

__attribute__((used)) static void wbscl_set_scaler_filter(
	struct dcn20_dwbc *dwbc20,
	uint32_t taps,
	enum wbscl_coef_filter_type_sel filter_type,
	const uint16_t *filter)
{
	const int tap_pairs = (taps + 1) / 2;
	int phase;
	int pair;
	uint16_t odd_coef, even_coef;

	for (phase = 0; phase < (NUM_PHASES / 2 + 1); phase++) {
		for (pair = 0; pair < tap_pairs; pair++) {
			even_coef = filter[phase * taps + 2 * pair];
			if ((pair * 2 + 1) < taps)
				odd_coef = filter[phase * taps + 2 * pair + 1];
			else
				odd_coef = 0;

			REG_SET_3(WBSCL_COEF_RAM_SELECT, 0,
				WBSCL_COEF_RAM_TAP_PAIR_IDX, pair,
				WBSCL_COEF_RAM_PHASE, phase,
				WBSCL_COEF_RAM_FILTER_TYPE, filter_type);

			REG_SET_4(WBSCL_COEF_RAM_TAP_DATA, 0,
				/* Even tap coefficient (bits 1:0 fixed to 0) */
				WBSCL_COEF_RAM_EVEN_TAP_COEF, even_coef,
				/* Write/read control for even coefficient */
				WBSCL_COEF_RAM_EVEN_TAP_COEF_EN, 1,
				/* Odd tap coefficient (bits 1:0 fixed to 0) */
				WBSCL_COEF_RAM_ODD_TAP_COEF, odd_coef,
				/* Write/read control for odd coefficient */
				WBSCL_COEF_RAM_ODD_TAP_COEF_EN, 1);
		}
	}
}