#pragma once

#include "quantum.h"
#include "keycode_config.h"
#include "quantum/e_macro.h"
#include "keymap_introspection.h"
#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

bool process_e_macro(uint16_t keycode, keyrecord_t *record);
