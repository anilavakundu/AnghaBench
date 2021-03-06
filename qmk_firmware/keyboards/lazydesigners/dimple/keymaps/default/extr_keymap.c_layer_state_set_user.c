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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  HSV_GOLD ; 
 int /*<<< orphan*/  HSV_GREEN ; 
 int /*<<< orphan*/  HSV_RED ; 
 int /*<<< orphan*/  HSV_WHITE ; 
#define  _ADJUST 130 
#define  _LOWER 129 
#define  _RAISE 128 
 int biton32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rgblight_sethsv_noeeprom (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  update_tri_layer_state (int /*<<< orphan*/ ,int,int,int) ; 

uint32_t layer_state_set_user(uint32_t state) {
	state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
	switch (biton32(state)) {
		case _LOWER:
			rgblight_sethsv_noeeprom(HSV_GREEN);
			break;
		case _RAISE:
			rgblight_sethsv_noeeprom(HSV_GOLD);
			break;
		case _ADJUST:
			rgblight_sethsv_noeeprom(HSV_RED);
			break;
		default:
			rgblight_sethsv_noeeprom(HSV_WHITE);
			break;
	}
	return state;
}