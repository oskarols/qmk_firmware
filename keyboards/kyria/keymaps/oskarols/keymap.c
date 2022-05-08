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
#include QMK_KEYBOARD_H

#include "keymap_swedish.h"

// Since SEND_STRING() defaults to US ANSI
#include "sendstring_swedish.h"

enum layers {
    _MAC_QWERTY = 0,
    _QWERTY,
    _QWERTY_GAMING,
    _MSYM, // Mac Symbol
    _SYM, // Symbol
    _NAV,
    _ADJUST,
    _MAC_HOMEROW,
    _HOMEROW,
};

// Custom keys

enum CUSTOM_KEYCODES {
  // To not have to write the space afterwards on ~ and ^
  // Basically not used this way in Swedish anyway.
  CK_TILDE = SAFE_RANGE,
  CK_CARET,
  CK_BTCKS
};

// Mac Home Rows CASG


// Left-hand home row mods
#define MHOME_A LCTL_T(KC_A)
#define MHOME_S LALT_T(KC_S)
#define MHOME_D LSFT_T(KC_D)
#define MHOME_F LGUI_T(KC_F)

// Right-hand home row mods
// CMD ALT SHIFT CTRL
#define MHOME_J RGUI_T(KC_J)
#define MHOME_K RSFT_T(KC_K)
#define MHOME_L RALT_T(KC_L)
#define MHOME_SCLN RCTL_T(KC_SCLN)


// All others (Windows, Linux etc) Home Rows

#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
// CMD ALT SHIFT CTRL
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Mac QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |NAV/ESC |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | Cmd  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | Hypr |LShift|  |LShift|Caps  |   N  |   M  | ,  ; | . :  | - _  |  ADJ   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Space| Tab  | Bksp | Play |
 *                        |      |      | Alt  | NAV  | SYMB |  | HR   | SYM  |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MAC_QWERTY] = LAYOUT(
      MT(MOD_RGUI, KC_ESC),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,       _______,
      MT(MOD_LCTL, KC_BSPC),  MHOME_A, MHOME_S, MHOME_D, MHOME_F, KC_G,                                        KC_H,  MHOME_J, MHOME_K, MHOME_L, MHOME_SCLN, _______,
      KC_LSFT,                KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_HYPR, KC_LSFT, KC_LSFT, KC_CAPS, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    MO(_ADJUST),
              KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_NAV, KC_SPC), KC_MEH, LT(_MAC_HOMEROW, KC_ENT), LT(_MSYM, KC_SPC), KC_TAB,  KC_BSPC, KC_MPLY
    ),

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |NAV/ESC |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | GUI  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | Gui  |LShift|  |LShift|Caps  |   N  |   M  | ,  ; | . :  | - _  |  ADJ   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter|LShift| Tab  | Bksp | Play |
 *                        |      |      | Alt  | NAV  | SYMB |  | SYMB |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      MT(MOD_RGUI, KC_ESC),   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
      MT(MOD_LCTL, KC_BSPC),  HOME_A, HOME_S, HOME_D, HOME_F, KC_G,                                          KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, _______,
      KC_LSFT,                KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,    KC_LGUI,   KC_LSFT, KC_LSFT, KC_CAPS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_ADJUST),
              KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_NAV, KC_SPC), LT(_SYM, KC_ESC), LT(_HOMEROW, KC_ENT), LT(_SYM, KC_SPC), KC_TAB,  KC_BSPC, KC_MPLY
    ),

/*
 * Base Layer: QWERTY GAMING
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |NAV/ESC |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | GUI  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | Caps |LShift|  |LShift|Caps  |   N  |   M  | ,  ; | . :  | - _  |  ADJ   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter|LShift| Tab  | Bksp | Play |
 *                        |      |      | Alt  | NAV  | SYMB |  | SYMB |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY_GAMING] = LAYOUT(
      MT(MOD_RGUI, KC_ESC),   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
      MT(MOD_LCTL, KC_BSPC),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
      KC_LSFT,                KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LGUI,   KC_LSFT, KC_LSFT, KC_CAPS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_ADJUST),
              KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_NAV, KC_SPC), LT(_SYM, KC_ESC), LT(_HOMEROW, KC_ENT), LT(_SYM, KC_SPC), KC_TAB,  KC_BSPC, KC_MPLY
    ),
/*
 * Lower Layer: Mac Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  \   |  /   |  <   |  >   |  =   |                              |   $  |  #   |  @   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  {   |  }   |  (   |  )   |  |   |                              |   %  |  +   |  '   |  "   |  `   |   ´    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  !   |  ?   |  [   |  ]   |      |      |      |  |      |      |      |  *   |  ^   |  ~   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MSYM] = LAYOUT(
      _______, S(A(KC_7)), S(KC_7), KC_GRAVE, S(KC_GRAVE), S(KC_0),                                   A(KC_4), S(KC_3), A(KC_2), S(KC_6), _______, _______,
      _______, S(A(KC_8)), S(A(KC_9)), S(KC_8), S(KC_9), A(KC_7),                                     S(KC_5), KC_MINS, KC_BSLS, S(KC_2), CK_BTCKS, KC_EQL,
      _______, S(KC_1),    S(KC_MINS), A(KC_8), A(KC_9), _______, _______, _______, _______, _______, _______, S(KC_BSLS), CK_CARET, CK_TILDE, _______, _______,
                                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  \   |  /   |  <   |  >   |  =   |                              |   $  |  #   |  @   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  {   |  }   |  (   |  )   |  |   |                              |   %  |  +   |  '   |  "   |  `   |   ´    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  !   |  ?   |  [   |  ]   |      |      |      |  |      |      |      |  *   |  ^   |  ~   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, ALGR(KC_MINS), S(KC_7), KC_NUBS, S(KC_NUBS), S(KC_0),                                        ALGR(KC_4), S(KC_3), ALGR(KC_2), S(KC_6), _______, _______,
      _______, ALGR(KC_7), ALGR(KC_0), S(KC_8), S(KC_9), ALGR(KC_NUBS),                                     S(KC_5), KC_MINS, KC_BSLS, S(KC_2), CK_BTCKS, KC_EQL,
      _______, S(KC_1),    S(KC_MINS), ALGR(KC_8), ALGR(KC_9), _______, _______, _______, _______, _______, _______, S(KC_BSLS), CK_CARET, CK_TILDE, _______, _______,
                                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Mute   |      |  1   |  2   |  3   |      |                              |      | Prev |      | Next |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Vol+   |  0   |  4   |  5   |  6   |      |                              | PgUp |   ←  |   ↑  |   →  | Mou1 | Mou2   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Vol-   |      |  7   |  8   |  9   |      |      |      |  |      |      | PgDw | Home |   ↓  | End  | Mou3 |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      KC_MUTE, _______, KC_1, KC_2, KC_3, _______,                                     _______,   KC_MPRV, _______, KC_MNXT, KC_BTN1, _______,
      KC_VOLU, KC_0,    KC_4, KC_5, KC_6, _______,                                     KC_PGUP,   KC_LEFT, KC_UP,   KC_RGHT, KC_BTN2, _______,
      KC_VOLD, _______, KC_7, KC_8, KC_9, _______, _______, _______, _______, _______, KC_PGDOWN, KC_HOME, KC_DOWN, KC_END,  KC_BTN3, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB, changing default layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |  F1  |  F2  |  F3  | F10  |                              |      |      |      |Gaming| Win  | Mac    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  F4  |  F5  |  F6  | F11  |                              |      | BRT↑ |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  F7  |  F8  |  F9  | F12  |      |      |  |      |      |      | BRT↓ |      |      | Reset|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,                                      _______, _______, _______, DF(_QWERTY_GAMING), DF(_QWERTY), DF(_MAC_QWERTY),
      _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,                                      _______, KC_BRIU, _______, _______, _______, _______,
      _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______, _______, _______, _______, _______, KC_BRID, _______, _______, RESET,   _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Mac: Layer used as overlay to enable homerow mods in e.g. symbol layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  Ctl |  Alt |  Sft |  Cmd |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MAC_HOMEROW] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_RCTL, KC_LALT, KC_LSFT, KC_LCMD, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Layer used as overlay to enable homerow mods in e.g. symbol layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  Win |  Alt |  Sft | Ctrl |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_HOMEROW] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_RGUI, KC_LALT, KC_LSFT, KC_LCTRL, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/*
 *   ___  _     _____ ____    ____
 *  / _ \| |   | ____|  _ \  / ___|  ___ _ __ ___  ___ _ __
 * | | | | |   |  _| | | | | \___ \ / __| '__/ _ \/ _ \ '_ \
 * | |_| | |___| |___| |_| |  ___) | (__| | |  __/  __/ | | |
 *  \___/|_____|_____|____/  |____/ \___|_|  \___|\___|_| |_|
 *
 */

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    // works better than `get_highest_layer` since temp "overlay" layers like Nav
    // Wouldn't show up properly with `get_highest_layer`
    uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);


    switch (layer) {
        case _MAC_QWERTY:
            oled_write_P(PSTR("Mac Qwerty "), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Qwerty "), false);
            break;
        case _QWERTY_GAMING:
            oled_write_P(PSTR("Gaming "), false);
            break;
        case _MSYM:
            oled_write_P(PSTR("Mac Symbol "), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbol "), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust "), false);
            break;
        case _MAC_HOMEROW:
            oled_write_P(PSTR("Mods "), false);
            break;
        default:
            oled_write_P(PSTR("Undefined "), false);
    }
    oled_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CK_TILDE:
      if (record->event.pressed) {
        uint16_t keycode = IS_LAYER_ON(_MSYM)
          ? A(KC_RBRC)
          : ALGR(KC_RBRC);
        tap_code16(keycode);
        tap_code16(KC_SPC);
      }
      return false;
    case CK_CARET:
      if (record->event.pressed) {
        tap_code16(S(KC_RBRC));
        tap_code16(KC_SPC);
      }
      return false;
    case CK_BTCKS:
      if (record->event.pressed) {
        tap_code16(S(KC_EQL));
        tap_code16(KC_SPC);
      }
      return false;
    default:
      return true;
  }
}

/*
 *  _  __             ____                _
 * | |/ /___ _   _   / ___|___  _ __ ___ | |__   ___  ___
 * | ' // _ \ | | | | |   / _ \| '_ ` _ \| '_ \ / _ \/ __|
 * | . \  __/ |_| | | |__| (_) | | | | | | |_) | (_) \__ \
 * |_|\_\___|\__, |  \____\___/|_| |_| |_|_.__/ \___/|___/
 *           |___/
 */

enum combos {
  AO,
  AE,
  OE,
  UE
};

// A + O = Å
const uint16_t PROGMEM ao_combo[] = {KC_A, KC_O, COMBO_END};

// A + E = Ä
const uint16_t PROGMEM ae_combo[] = {KC_A, KC_E, COMBO_END};

// O + E = Ö
const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};

// U + E = Ü
const uint16_t PROGMEM ue_combo[] = {KC_U, KC_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [AO] = COMBO(ao_combo, SE_ARNG),
  [AE] = COMBO(ae_combo, SE_ADIA),
  [OE] = COMBO(oe_combo, SE_ODIA),
  [UE] = COMBO_ACTION(ue_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case UE:
      if (pressed) {
        tap_code(SE_DIAE);
        tap_code(KC_U);
      }
      break;
  }
}
/*
 *  _____                     _
 * | ____|_ __   ___ ___   __| | ___ _ __
 * |  _| | '_ \ / __/ _ \ / _` |/ _ \ '__|
 * | |___| | | | (_| (_) | (_| |  __/ |
 * |_____|_| |_|\___\___/ \__,_|\___|_|
 *
 */


#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    // Probably the left side encoder (not enabled)
    if (index == 0) {
        // mouse wheel
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }

    // right side encoder
    else if (index == 1) {
        if (IS_LAYER_ON(_MAC_QWERTY)) {
            // Mouse wheel scroll
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        }
        else if (IS_LAYER_ON(_MSYM)) {
            if (clockwise) {
                tap_code16(G(KC_Y));
            } else {
                tap_code16(G(KC_Z));
            }
        }
        else if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        }
    }
}
#endif


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAV, KC_SPC):
            return true;
        default:
            return false;
    }
}
