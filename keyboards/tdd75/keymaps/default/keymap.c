// Copyright 2025 TheDeathDragon
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum/e_macro.h"

// for Caps Lock LED default off
bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        gpio_set_pin_output(B0);
        gpio_write_pin_low(B0);
    } else {
        gpio_set_pin_input(B0);
        gpio_write_pin_low(B0);
    }
    return false;
}

#if defined(KEY_CANCELLATION_ENABLE)
const key_cancellation_t PROGMEM key_cancellation_list[] = {
    // on key down
    //       |    key to be released
    //       |     |
    [0] = {KC_D, KC_A},
    [1] = {KC_A, KC_D},
    [2] = {KC_W, KC_S},
    [3] = {KC_S, KC_W},
};
#endif

#if defined(E_MACRO_ENABLE)
// Define the E Macro key sequence
const e_macro_t e_macro_list[] PROGMEM = {
    {KC_MS_BTN2, 20},  // Mouse Right Button
    {KC_MS_BTN1, 20},  // Mouse Left Button
    {KC_Q, 30},        // Q Key
    {KC_Q, 30},        // Q Key
};
#endif
/*
 * ,--------------------------------------------------------------------------------------.
 * |Esc | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 |      | DEL |     |
 * |------------------------------------------------------------|----|--------------------|
 * | GRV |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BSPC |      | HOME |
 * |------------------------------------------------------------|----|--------------------|
 * |Tab  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  |      | PGUP |
 * |--------------------------------------------------------.   |----|--------------------|
 * |CAPS |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |  # |    ENTER    | PGDN |
 * |------------------------------------------------------------|----|--------------------|
 * |LSFT |  \ |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / | RSFT |    |  UP  |      |
 * |--------------------------------------------------------------------------------------|
 * |LCTL | LGUI | LALT |       SPC                    | MO(1) | RCTL | LEFT | DOWN | RGHT |
 * `--------------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [1] = LAYOUT(KC_TRNS, KX_CAON, KX_CAOF, KX_EON, KX_EOFF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, NK_TOGG, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_TRNS, RGB_TOG, RGB_M_P, RGB_M_R, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT)
};
