#include "process_e_macro.h"
static bool e_macro_running = false;

bool process_e_macro(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_KEY_E_MACRO_ON:
            if (record->event.pressed) {
                keymap_config.e_macro_enable = true;
                eeconfig_update_keymap(keymap_config.raw);
#ifdef CONSOLE_ENABLE
                uprintf("E Macro On\n");
#endif
            }
            return false;

        case QK_KEY_E_MACRO_OFF:
            if (record->event.pressed) {
                keymap_config.e_macro_enable = false;
                eeconfig_update_keymap(keymap_config.raw);
#ifdef CONSOLE_ENABLE
                uprintf("E Macro Off\n");
#endif
            }
            return false;

        case QK_KEY_E_MACRO_TOGGLE:
            if (record->event.pressed) {
                keymap_config.e_macro_enable = !keymap_config.e_macro_enable;
                eeconfig_update_keymap(keymap_config.raw);
#ifdef CONSOLE_ENABLE
                uprintf("E Macro Toggle\n");
#endif
            }
            return false;

        case KC_E:
            if (keymap_config.e_macro_enable && !record->event.pressed && !e_macro_running) {
                e_macro_running = true;
#ifdef CONSOLE_ENABLE
                uprintf("===================E Macro Start===================\n");
                uprintf("Current Time: %d\n", timer_read32());
#endif

                // Execute E Macro Sequence
                for (uint16_t i = 0; i < e_macro_count(); i++) {
                    e_macro_t macro = e_macro_get(i);
                    tap_code_delay(macro.keycode, macro.delay);
                    if (i < e_macro_count() - 1) {
                        wait_ms(macro.delay);
                    }
                }

#ifdef CONSOLE_ENABLE
                uprintf("E Macro Completed, Time: %d ms\n", timer_read32());
                uprintf("===================E Macro End===================\n");
#endif

                e_macro_running = false;
                return false; // Prevent original E key output
            }
            break;
    }

    return true;
}
