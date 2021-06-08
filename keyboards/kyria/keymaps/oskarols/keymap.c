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
    _QWERTY = 0,
    _SYMBOL,
    _NAV,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  + ?   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LShift|LShift|  |LShift|LShift|   N  |   M  | ,  ; | . :  | - _  |  Adj   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Lead| Tab  | Bksp | AltGr|
 *                        |      |      | Alt  | Symb | Nav  |  | Nav  |     |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      LT(_NAV, KC_ESC),       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      MT(MOD_LCTL, KC_BSPC),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT,                 KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LSFT,   KC_LSFT, KC_LSFT, KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_ADJUST),
              KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_SYMBOL, KC_SPC), LT(_NAV, KC_ESC), LT(_NAV, KC_ENT), KC_LEAD, KC_TAB,  KC_BSPC, KC_RALT
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |      |      |      |      |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  |  =   |  ;   |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOL] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, _______, _______, _______, _______, KC_BSLS,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 _______, _______, _______, KC_SCLN, KC_EQL,  KC_EQL,  KC_SCLN, _______, _______, _______
    ),
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              | PgUp | Left | Up   | Right| BroF |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|      |      |  |      |      | PgDw | Home | Down | End  | BroB |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_PGUP, KC_LEFT, KC_UP,   KC_RGHT, KC_WWW_FORWARD, _______,
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______, _______, _______, KC_PGDOWN, KC_HOME, KC_DOWN, KC_END, KC_WWW_BACK, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      | Reset|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, RESET, _______,
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOL, _NAV, _ADJUST);
}

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
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

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


/*
 *  _  __             ____                _
 * | |/ /___ _   _   / ___|___  _ __ ___ | |__   ___  ___
 * | ' // _ \ | | | | |   / _ \| '_ ` _ \| '_ \ / _ \/ __|
 * | . \  __/ |_| | | |__| (_) | | | | | | |_) | (_) \__ \
 * |_|\_\___|\__, |  \____\___/|_| |_| |_|_.__/ \___/|___/
 *           |___/
 */

/*
 * J + Left half combos
 *
 * ,------------------------------------------------.
 * |        |   \   |   /   |   <   |   >   |   =   |
 * |--------+-------+-------+-------+-------+-------|
 * |        |   {   |   }   |   (   |   )   |   |   |
 * |--------+-------+-------+-------+-------+-------+-------------.
 * |        |       |       |   [   |   ]   |       |      |      |
 * `------------------------+-------+-------+-------+------+------|
 *                          |       |       |       |      |      |
 *                          |       |       |       |      |      |
 *                          `------------------------------------'
 */

 /*
 * K + Left half combos
 *
 * ,------------------------------------------------.
 * |        |   !   |   @   |   #   |   &   |   ?   |
 * |--------+-------+-------+-------+-------+-------|
 * |        |   %   |   +   |   '   |   "   |   `   |
 * |--------+-------+-------+-------+-------+-------+-------------.
 * |        |   ^   |   *   |   ~   |   $   |   €   |      |      |
 * `------------------------+-------+-------+-------+------+------|
 *                          |       |       |       |      |      |
 *                          |       |       |       |      |      |
 *                          `------------------------------------'
 */
enum combos {
  AO,
  AE,
  OE,
  UE,

  JQ,
  JW,
  JE,
  JR,
  JT,

  JA,
  JS,
  JD,
  JF,
  JG,

  JZ,
  JX,
  JC,
  JV,
  JB,


  KQ,
  KW,
  KE,
  KR,
  KT,

  KA,
  KS,
  KD,
  KF,
  KG,

  KZ,
  KX,
  KC,
  KV,
  KB
};

// A + O = Å
const uint16_t PROGMEM ao_combo[] = {KC_A, KC_O, COMBO_END};

// A + E = Ä
const uint16_t PROGMEM ae_combo[] = {KC_A, KC_E, COMBO_END};

// O + E = Ö
const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};

// U + . = Ü
const uint16_t PROGMEM ue_combo[] = {KC_U, KC_E, COMBO_END};


const uint16_t PROGMEM jq_combo[] = {KC_J, KC_Q, COMBO_END};
const uint16_t PROGMEM jw_combo[] = {KC_J, KC_W, COMBO_END};
const uint16_t PROGMEM je_combo[] = {KC_J, KC_E, COMBO_END};
const uint16_t PROGMEM jr_combo[] = {KC_J, KC_R, COMBO_END};
const uint16_t PROGMEM jt_combo[] = {KC_J, KC_T, COMBO_END};

const uint16_t PROGMEM ja_combo[] = {KC_J, KC_A, COMBO_END};
const uint16_t PROGMEM js_combo[] = {KC_J, KC_S, COMBO_END};
const uint16_t PROGMEM jd_combo[] = {KC_J, KC_D, COMBO_END};
const uint16_t PROGMEM jf_combo[] = {KC_J, KC_F, COMBO_END};
const uint16_t PROGMEM jg_combo[] = {KC_J, KC_G, COMBO_END};

const uint16_t PROGMEM jz_combo[] = {KC_J, KC_Z, COMBO_END};
const uint16_t PROGMEM jx_combo[] = {KC_J, KC_X, COMBO_END};
const uint16_t PROGMEM jc_combo[] = {KC_J, KC_C, COMBO_END};
const uint16_t PROGMEM jv_combo[] = {KC_J, KC_V, COMBO_END};
const uint16_t PROGMEM jb_combo[] = {KC_J, KC_B, COMBO_END};


const uint16_t PROGMEM kq_combo[] = {KC_K, KC_Q, COMBO_END};
const uint16_t PROGMEM kw_combo[] = {KC_K, KC_W, COMBO_END};
const uint16_t PROGMEM ke_combo[] = {KC_K, KC_E, COMBO_END};
const uint16_t PROGMEM kr_combo[] = {KC_K, KC_R, COMBO_END};
const uint16_t PROGMEM kt_combo[] = {KC_K, KC_T, COMBO_END};

const uint16_t PROGMEM ka_combo[] = {KC_K, KC_A, COMBO_END};
const uint16_t PROGMEM ks_combo[] = {KC_K, KC_S, COMBO_END};
const uint16_t PROGMEM kd_combo[] = {KC_K, KC_D, COMBO_END};
const uint16_t PROGMEM kf_combo[] = {KC_K, KC_F, COMBO_END};
const uint16_t PROGMEM kg_combo[] = {KC_K, KC_G, COMBO_END};

const uint16_t PROGMEM kz_combo[] = {KC_K, KC_Z, COMBO_END};
const uint16_t PROGMEM kx_combo[] = {KC_K, KC_X, COMBO_END};
const uint16_t PROGMEM kc_combo[] = {KC_K, KC_C, COMBO_END};
const uint16_t PROGMEM kv_combo[] = {KC_K, KC_V, COMBO_END};
const uint16_t PROGMEM kb_combo[] = {KC_K, KC_B, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [AO] = COMBO(ao_combo, SE_ARNG),
  [AE] = COMBO(ae_combo, SE_ADIA),
  [OE] = COMBO(oe_combo, SE_ODIA),
  [UE] = COMBO_ACTION(ue_combo),

  [JQ] = COMBO_ACTION(jq_combo),
  [JW] = COMBO_ACTION(jw_combo),
  [JE] = COMBO_ACTION(je_combo),
  [JR] = COMBO_ACTION(jr_combo),
  [JT] = COMBO_ACTION(jt_combo),

  [JA] = COMBO_ACTION(ja_combo),
  [JS] = COMBO_ACTION(js_combo),
  [JD] = COMBO_ACTION(jd_combo),
  [JF] = COMBO_ACTION(jf_combo),
  [JG] = COMBO_ACTION(jg_combo),

  [JZ] = COMBO_ACTION(jz_combo),
  [JX] = COMBO_ACTION(jx_combo),
  [JC] = COMBO_ACTION(jc_combo),
  [JV] = COMBO_ACTION(jv_combo),
  [JB] = COMBO_ACTION(jb_combo),


  [KQ] = COMBO_ACTION(kq_combo),
  [KW] = COMBO_ACTION(kw_combo),
  [KE] = COMBO_ACTION(ke_combo),
  [KR] = COMBO_ACTION(kr_combo),
  [KT] = COMBO_ACTION(kt_combo),

  [KA] = COMBO_ACTION(ka_combo),
  [KS] = COMBO_ACTION(ks_combo),
  [KD] = COMBO_ACTION(kd_combo),
  [KF] = COMBO_ACTION(kf_combo),
  [KG] = COMBO_ACTION(kg_combo),

  [KZ] = COMBO_ACTION(kz_combo),
  [KX] = COMBO_ACTION(kx_combo),
  [KC] = COMBO_ACTION(kc_combo),
  [KV] = COMBO_ACTION(kv_combo),
  [KB] = COMBO_ACTION(kb_combo)

};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case UE:
      if (pressed) {
        tap_code(SE_DIAE);
        tap_code(KC_U);
      }
      break;

    // J COMBOS

    // left row 1
    case JQ:
      if (pressed) {
        SEND_STRING("\\");
      }
      break;
    case JW:
      if (pressed) {
        SEND_STRING("/");
      }
      break;
    case JE:
      if (pressed) {
        SEND_STRING("<");
      }
      break;
    case JR:
      if (pressed) {
        SEND_STRING(">");
      }
      break;
    case JT:
      if (pressed) {
        SEND_STRING("=");
      }
      break;

    // left row 2
    case JA:
      if (pressed) {
        SEND_STRING("{");
      }
      break;
    case JS:
      if (pressed) {
        SEND_STRING("}");
      }
      break;
    case JD:
      if (pressed) {
        SEND_STRING("(");
      }
      break;
    case JF:
      if (pressed) {
        SEND_STRING(")");
      }
      break;
    case JG:
      if (pressed) {
        SEND_STRING("|");
      }
      break;

    // left row 3
    case JZ:
      if (pressed) {
        SEND_STRING("");
      }
      break;
    case JX:
      if (pressed) {
        SEND_STRING("");
      }
      break;
    case JC:
      if (pressed) {
        SEND_STRING("[");
      }
      break;
    case JV:
      if (pressed) {
        SEND_STRING("]");
      }
      break;
    case JB:
      if (pressed) {
        SEND_STRING("");
      }
      break;

    // K COMBOS

    // left row 1
    case KQ:
      if (pressed) {
        SEND_STRING("!");
      }
      break;
    case KW:
      if (pressed) {
        SEND_STRING("@");
      }
      break;
    case KE:
      if (pressed) {
        SEND_STRING("#");
      }
      break;
    case KR:
      if (pressed) {
        SEND_STRING("&");
      }
      break;
    case KT:
      if (pressed) {
        SEND_STRING("?");
      }
      break;

    // left row 2
    case KA:
      if (pressed) {
        SEND_STRING("%");
      }
      break;
    case KS:
      if (pressed) {
        SEND_STRING("+");
      }
      break;
    case KD:
      if (pressed) {
        SEND_STRING("'");
      }
      break;
    case KF:
      if (pressed) {
        SEND_STRING("\"");
      }
      break;
    case KG:
      if (pressed) {
        SEND_STRING("`");
      }
      break;

    // left row 3
    case KZ:
      if (pressed) {
        SEND_STRING("^");
      }
      break;
    case KX:
      if (pressed) {
        SEND_STRING("*");
      }
      break;
    case KC:
      if (pressed) {
        SEND_STRING("~");
      }
      break;
    case KV:
      if (pressed) {
        SEND_STRING("$");
      }
      break;
    case KB:
      if (pressed) {
        SEND_STRING("");
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
        if (IS_LAYER_ON(_QWERTY)) {
            // Mouse wheel scroll
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        }
        else if (IS_LAYER_ON(_SYMBOL)) {
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        }
        else if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
}
#endif


/*  _                   _             _  __
 * | |    ___  __ _  __| | ___ _ __  | |/ /___ _   _
 * | |   / _ \/ _` |/ _` |/ _ \ '__| | ' // _ \ | | |
 * | |__|  __/ (_| | (_| |  __/ |    | . \  __/ |_| |
 * |_____\___|\__,_|\__,_|\___|_|    |_|\_\___|\__, |
 *                                             |___/
 *   ____                _
 *  / ___|___  _ __ ___ | |__   ___  ___
 * | |   / _ \| '_ ` _ \| '_ \ / _ \/ __|
 * | |__| (_) | | | | | | |_) | (_) \__ \
 *  \____\___/|_| |_| |_|_.__/ \___/|___/
 *k
 */

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("<");
    }
    SEQ_TWO_KEYS(KC_F, KC_J) {
      SEND_STRING(">");
    }

    SEQ_ONE_KEY(KC_D) {
      SEND_STRING("(");
    }
    SEQ_TWO_KEYS(KC_D, KC_J) {
      SEND_STRING(")");
    }

    SEQ_ONE_KEY(KC_S) {
      SEND_STRING("{");
    }
    SEQ_TWO_KEYS(KC_S, KC_J) {
      SEND_STRING("}");
    }

    SEQ_ONE_KEY(KC_A) {
      SEND_STRING("[");
    }
    SEQ_TWO_KEYS(KC_A, KC_J) {
      SEND_STRING("]");
    }
  }
}
