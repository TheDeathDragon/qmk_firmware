// Copyright 2022 Nick Brassel (@tzarc)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "quantum/e_macro.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Key mapping

// Get the number of layers defined in the keymap, stored in firmware rather than any other persistent storage
uint8_t keymap_layer_count_raw(void);
// Get the number of layers defined in the keymap, potentially stored dynamically
uint8_t keymap_layer_count(void);

// Get the keycode for the keymap location, stored in firmware rather than any other persistent storage
uint16_t keycode_at_keymap_location_raw(uint8_t layer_num, uint8_t row, uint8_t column);
// Get the keycode for the keymap location, potentially stored dynamically
uint16_t keycode_at_keymap_location(uint8_t layer_num, uint8_t row, uint8_t column);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Encoder mapping

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// Get the number of layers defined in the encoder map, stored in firmware rather than any other persistent storage
uint8_t encodermap_layer_count_raw(void);
// Get the number of layers defined in the encoder map, potentially stored dynamically
uint8_t encodermap_layer_count(void);

// Get the keycode for the encoder mapping location, stored in firmware rather than any other persistent storage
uint16_t keycode_at_encodermap_location_raw(uint8_t layer_num, uint8_t encoder_idx, bool clockwise);
// Get the keycode for the encoder mapping location, potentially stored dynamically
uint16_t keycode_at_encodermap_location(uint8_t layer_num, uint8_t encoder_idx, bool clockwise);

#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dip Switch mapping

#if defined(DIP_SWITCH_ENABLE) && defined(DIP_SWITCH_MAP_ENABLE)

// Get the keycode for the dip_switch mapping location, stored in firmware rather than any other persistent storage
uint16_t keycode_at_dip_switch_map_location_raw(uint8_t switch_idx, bool on);
// Get the keycode for the dip_switch mapping location, potentially stored dynamically
uint16_t keycode_at_dip_switch_map_location(uint8_t switch_idx, bool on);

#endif // defined(DIP_SWITCH_ENABLE) && defined(DIP_SWITCH_MAP_ENABLE)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Combos

#if defined(COMBO_ENABLE)

// Forward declaration of combo_t so we don't need to deal with header reordering
struct combo_t;
typedef struct combo_t combo_t;

// Get the number of combos defined in the user's keymap, stored in firmware rather than any other persistent storage
uint16_t combo_count_raw(void);
// Get the number of combos defined in the user's keymap, potentially stored dynamically
uint16_t combo_count(void);

// Get the combo definition, stored in firmware rather than any other persistent storage
combo_t* combo_get_raw(uint16_t combo_idx);
// Get the combo definition, potentially stored dynamically
combo_t* combo_get(uint16_t combo_idx);

#endif // defined(COMBO_ENABLE)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tap Dance

#if defined(TAP_DANCE_ENABLE)

// Forward declaration of tap_dance_action_t so we don't need to deal with header reordering
struct tap_dance_action_t;
typedef struct tap_dance_action_t tap_dance_action_t;

// Get the number of tap dances defined in the user's keymap, stored in firmware rather than any other persistent storage
uint16_t tap_dance_count_raw(void);
// Get the number of tap dances defined in the user's keymap, potentially stored dynamically
uint16_t tap_dance_count(void);

// Get the tap dance definitions, stored in firmware rather than any other persistent storage
tap_dance_action_t* tap_dance_get_raw(uint16_t tap_dance_idx);
// Get the tap dance definitions, potentially stored dynamically
tap_dance_action_t* tap_dance_get(uint16_t tap_dance_idx);

#endif // defined(TAP_DANCE_ENABLE)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Key Overrides

#if defined(KEY_OVERRIDE_ENABLE)

// Forward declaration of key_override_t so we don't need to deal with header reordering
struct key_override_t;
typedef struct key_override_t key_override_t;

// Get the number of key overrides defined in the user's keymap, stored in firmware rather than any other persistent storage
uint16_t key_override_count_raw(void);
// Get the number of key overrides defined in the user's keymap, potentially stored dynamically
uint16_t key_override_count(void);

// Get the key override definitions, stored in firmware rather than any other persistent storage
const key_override_t* key_override_get_raw(uint16_t key_override_idx);
// Get the key override definitions, potentially stored dynamically
const key_override_t* key_override_get(uint16_t key_override_idx);

#endif // defined(KEY_OVERRIDE_ENABLE)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Key Cancellation

#if defined(KEY_CANCELLATION_ENABLE)
// Forward declaration of key_cancellation_t so we don't need to deal with header reordering
struct key_cancellation_t;
typedef struct key_cancellation_t key_cancellation_t;
// Get the number of key cancellations defined in the user's keymap, stored in firmware rather than any other persistent storage
uint16_t key_cancellation_count_raw(void);
// Get the number of key cancellations defined in the user's keymap, potentially stored dynamically
uint16_t key_cancellation_count(void);
// Get the keycodes for the key cancellation, stored in firmware rather than any other persistent storage
key_cancellation_t key_cancellation_get_raw(uint16_t idx);
// Get the keycodes for the key cancellation, stored in firmware, potentially stored dynamically
key_cancellation_t key_cancellation_get(uint16_t idx);
#endif // defined(KEY_CANCELLATION_ENABLE)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// E Macro

#if defined(E_MACRO_ENABLE)
// Forward declaration of e_macro_t so we don't need to deal with header reordering
struct e_macro_t;
typedef struct e_macro_t e_macro_t;

// Get the number of E macros defined in the user's keymap, stored in firmware rather than any other persistent storage
uint16_t e_macro_count_raw(void);
// Get the number of E macros defined in the user's keymap, potentially stored dynamically
uint16_t e_macro_count(void);

// Get the E macro definitions, stored in firmware rather than any other persistent storage
e_macro_t e_macro_get_raw(uint16_t idx);
// Get the E macro definitions, potentially stored dynamically
e_macro_t e_macro_get(uint16_t idx);
#endif // defined(E_MACRO_ENABLE)
