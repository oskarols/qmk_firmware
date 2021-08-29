/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

// hardcode setting the master to always be on right side
# define MASTER_RIGHT

# define COMBO_COUNT 4

// decreased from default of 200 to get fewer false positives when typing normally
# define COMBO_TERM 50

# define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 24

// try to fix the space layer problems
# define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
# define IGNORE_MOD_TAP_INTERRUPT

// enables writing e.g. "camelCase" with home row mods
// has downside of disabling holding a char to output the char
# define TAPPING_FORCE_HOLD

// time to complete the combo sequence
// # define LEADER_TIMEOUT 150
// # define LEADER_PER_KEY_TIMING 150