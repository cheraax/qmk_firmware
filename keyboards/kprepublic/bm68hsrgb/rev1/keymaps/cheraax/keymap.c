/* Copyright 2021 peepeetee
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
#define MACRO00 LGUI(KC_SPC)
#define MACRO01 RCTL(KC_ENT)

// // Defines names for use in layer keycodes and the keymap
// enum layer_names {
//     _BASE,
//     _FN
// };
// It's easy. You assign F(0) to the key in question in the keymap array. Then you define fn_actions, like this:

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_TOGGLE(2)
};

// Then you define TAPPING_TOGGLE inside your keymap's config.h file:




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        KC_ESC,    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_MINS, KC_EQL,  KC_BSPC,   KC_GRV,
        KC_TAB,    KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_LBRC, KC_RBRC, KC_BSLS, KC_INS,
        KC_CAPS,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,     KC_ENT,    KC_DEL,
        KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,  KC_LSFT, KC_UP,    MACRO00,
        KC_LCTL,KC_LGUI,KC_LALT,                            KC_SPC,                       MO(1), MO(2), MO(3),KC_LEFT,KC_DOWN,KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, KC_PSCR,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,RGB_HUI,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,     _______,    RGB_HUD,
        _______, _______, _______, _______, _______, QK_BOOT, _______,  _______, _______, _______, _______,      _______,   RGB_VAI, RGB_RMOD,
        _______, MAGIC_TOGGLE_NKRO,_______,                RGB_TOG,                       _______, _______, _______, RGB_SAI,RGB_VAD,RGB_SAD
    ),
    [2] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______,                         _______,                      _______, _______, _______, _______, _______, _______ 
    ),
    [3] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_PAUS, KC_PSCR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MACRO01, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
        _______, _______, _______,                         _______,                      _______, _______, _______, KC_HOME, KC_PGDN, KC_END
    ),  
 };

/*
Template
    [ ] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,    _______,
        _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,   _______,  _______,
        _______,   _______,   _______,                    _______,                         _______, _______, _______, _______, _______,  _______
    ),
*/
