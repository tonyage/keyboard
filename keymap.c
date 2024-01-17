// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "os_detection.h"

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT(
    KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,                                        KC_6, KC_7,  KC_8,    KC_9,   KC_0,    KC_BSPC,
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                        KC_Y, KC_U,  KC_I,    KC_O,   KC_P,    KC_DEL,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                                        KC_H, KC_J,  KC_K,    KC_L,   KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,  KC_MUTE,               LCTL(KC_RCTL), KC_N, KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                    KC_LGUI, KC_LALT, LOWER, KC_SPC,                     KC_SPC, RAISE, KC_RALT, KC_MEH
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |SCRLCK|  v   |  v   |  [   |  ]   |  v   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   v  |  F6  |  F7  |  F8  |  F9  | F10  |                    | HOME | PGDN | PGUP | END  | PRSC |  v   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   v  |   v  |   v  |   v  |   v  |   v  |-------.    ,-------|  v   |  v   |  v   |  v   |  v   |  v   |
 * |------+------+------+------+------+------|RGB_TOG|    |   v   |------+------+------+------+------+------|
 * |   v  |  -_  |  =+  |   v  |   v  |   v  |-------|    |-------|  v   |  v   |  v   |  v   |  v   |  v   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_SCRL, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   LSFT(KC_F10),                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_TRNS,
    KC_TRNS, KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |MOD   | MODR |  S+  |  S-  |  B+  |  B-  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   v   |    |  L-C  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, RGB_SAI, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          RGB_MOD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |  MOD | VAL+ | VAL- |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  AC  |  CC  |      | BOOT |      |                    |      | SAT+ | SAT- |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Back |      | FRWD |      |      |-------.    ,-------| PREV | PLAY |      | NEXT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | HUE+ | HUE- |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                            RGB_MOD, RGB_VAI, RGB_VAD, KC_NO,   KC_NO, KC_NO,
    KC_NO, AC_TOGG, CW_TOGG, KC_NO,   QK_BOOT, KC_NO,                            KC_NO,   RGB_SAI, RGB_SAD, KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_WBAK, KC_WSCH, KC_WFWD, KC_NO,   KC_NO,                            KC_MPRV, KC_MPLY, KC_NO,   KC_MNXT, KC_NO, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,              KC_NO, KC_NO,   RGB_HUI, RGB_HUD, KC_NO,   KC_NO, KC_NO,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

