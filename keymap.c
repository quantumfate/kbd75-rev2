// Copyright 2017-2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    // QuantumFate
    QF_QUOTE = SAFE_RANGE,
    QF_UML, // original KC_QUOTE but shift inverted
    QF_VUP = KC_AUDIO_VOL_UP,
    QF_VDN = KC_AUDIO_VOL_DOWN,
    // Programmer dvorak
    PD_ND, // & and %
    PD_AT, // @ and ^
    PD_HS, // # and `
    PD_DS, // $ and ~
    PD_1,
    PD_2,
    PD_3,
    PD_4,
    PD_5,
    PD_6,
    PD_7,
    PD_8,
    PD_9,
    PD_0,
};

// assumes US
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Dvorak
    [0] = LAYOUT(
        KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, MO(1),   KC_DEL,
        PD_DS,   PD_ND,   PD_7,    PD_5,    PD_3,    PD_1,    PD_9,    PD_0,    PD_2,    PD_4,    PD_6,    PD_8,    PD_HS,   _______, KC_BSPC, KC_HOME,
        KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, PD_AT,   KC_BSLS,          KC_PGUP,
        KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,           KC_PGDN,
        KC_LSFT, MO(1),   QF_QUOTE,KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,          KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  KC_SPC,  QF_UML,                    KC_ALGR, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // Util
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______, _______, _______, _______, BL_DOWN, BL_TOGG, BL_UP,   BL_STEP, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______, _______
    ),
    // QWERTY
    //[2] = LAYOUT(
    //    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, MO(1),   KC_DEL,
    //    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC, KC_HOME,
    //    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    //    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
    //    KC_LSFT, MO(1),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
    //    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  KC_SPC,  KC_SPC,                    KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    //),

};


struct us_to_dvorak_t {
    uint8_t kd_us;
    const bool us_needs_shift;
};


// (first row) Number keys
struct us_to_dvorak_t QF_1 = { .kd_us = KC_1, .us_needs_shift = false },
                      QF_2 = { .kd_us = KC_2, .us_needs_shift = false },
                      QF_3 = { .kd_us = KC_3, .us_needs_shift = false },
                      QF_4 = { .kd_us = KC_4, .us_needs_shift = false },
                      QF_5 = { .kd_us = KC_5, .us_needs_shift = false },
                      QF_6 = { .kd_us = KC_6, .us_needs_shift = false },
                      QF_7 = { .kd_us = KC_7, .us_needs_shift = false },
                      QF_8 = { .kd_us = KC_8, .us_needs_shift = false },
                      QF_9 = { .kd_us = KC_9, .us_needs_shift = false },
                      QF_0 = { .kd_us = KC_0, .us_needs_shift = false };

// (second row) Special Character Keys
struct us_to_dvorak_t QF_LBRC_CURVED = { .kd_us = KC_9, .us_needs_shift = true },
                      QF_RBRC_CURVED = { .kd_us = KC_0, .us_needs_shift = true },
                      QF_RBRC_CURLY = { .kd_us = KC_RBRC, .us_needs_shift = true },
                      QF_PLUS = { .kd_us = KC_EQL, .us_needs_shift = true },
                      QF_LBRC_CURLY = { .kd_us = KC_LBRC, .us_needs_shift = true },
                      QF_RBRC_CORNER = { .kd_us = KC_RBRC, .us_needs_shift = false },
                      QF_LBRC_CORNER = { .kd_us = KC_LBRC, .us_needs_shift = false },
                      QF_EXLAMATION_POINT = { .kd_us = KC_1, .us_needs_shift = true },
                      QF_EQUAL = { .kd_us = KC_EQL, .us_needs_shift = false },
                      QF_ASTERISK = { .kd_us = KC_8, .us_needs_shift = true };

// (third row) RALT/AltGr Keys
struct us_to_dvorak_t QF_SPANISH_EXCLAMATION = { .kd_us = KC_1, .us_needs_shift = false },
                      QF_SPANISH_QUESTION = { .kd_us = KC_SLSH, .us_needs_shift = false },
                      QF_DIVISION = { .kd_us = KC_EQL, .us_needs_shift = true },
                      QF_FR_LSINGLE_QUOTE = { .kd_us = KC_9, .us_needs_shift = true },
                      QF_FR_RSINGLE_QUOTE = { .kd_us = KC_8, .us_needs_shift = true };
// (fourth row) RALT/AltGr Keys
struct us_to_dvorak_t QF_EXPONENT_ONE = { .kd_us = KC_1, .us_needs_shift = true },
                      QF_EXPONENT_TWO = { .kd_us = KC_2, .us_needs_shift = false },
                      QF_EXPONENT_THREE = { .kd_us = KC_3, .us_needs_shift = false },
                      QF_BULLET_POINT = { .kd_us = KC_4, .us_needs_shift = false },
                      QF_EURO = { .kd_us = KC_5, .us_needs_shift = false },
                      QF_FR_RDOUBLE_QUOTE = { .kd_us = KC_RBRC, .us_needs_shift = false },
                      QF_FR_LDOUBLE_QUOTE = { .kd_us = KC_LBRC, .us_needs_shift = false },
                      QF_MULTIPLY = { .kd_us = KC_EQL, .us_needs_shift = false };


// Specific keybinds
struct us_to_dvorak_t QF_SINGLE_QUOTE = { .kd_us = KC_QUOTE, .us_needs_shift = false },
                      QF_DOUBLE_QUOTE = { .kd_us = KC_QUOTE, .us_needs_shift = true },
                      QF_AT = { .kd_us = KC_2, .us_needs_shift = true },
                      QF_ZIRK= { .kd_us = KC_6, .us_needs_shift = true },
                      QF_HASH = { .kd_us = KC_3, .us_needs_shift = true },
                      QF_GRV = { .kd_us = KC_GRV, .us_needs_shift = false },
                      QF_DS = { .kd_us = KC_4, .us_needs_shift = true },
                      QF_TILDE = { .kd_us = KC_GRV, .us_needs_shift = true },
                      QF_AND = { .kd_us = KC_7, .us_needs_shift = true },
                      QF_PER = { .kd_us = KC_5, .us_needs_shift = true };

// Placeholder for no map
struct us_to_dvorak_t QF_NO_MAP = { .kd_us = KC_NO, .us_needs_shift = false };

bool qf_block_altgr_shift(uint8_t mod_state) {

    return (mod_state == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_ALGR))) || (mod_state == (MOD_BIT(KC_RSFT) | MOD_BIT(KC_ALGR)));
}

bool qf_block_altgr(uint8_t mod_state) {

    return mod_state & MOD_BIT(KC_ALGR);
}
/*
 * @brief Fires US-International Keyboard keycode's as if they were from programmer dvorak.
 */
uint8_t qf_process_mapping(uint8_t mod_state, struct us_to_dvorak_t *uppercase, struct us_to_dvorak_t *lowercase) {

    if (mod_state & MOD_MASK_SHIFT) {
        if (!uppercase->us_needs_shift) {
            del_mods(MOD_MASK_SHIFT);
        }
        register_code(uppercase->kd_us);
        return uppercase->kd_us;

    } else {
        if (lowercase->us_needs_shift) {
            add_mods(MOD_MASK_SHIFT);
        }
        register_code(lowercase->kd_us);
        return lowercase->kd_us;
    }
}


uint8_t qf_process_press(uint8_t mod_state, struct us_to_dvorak_t *uppercase, struct us_to_dvorak_t *lowercase, struct us_to_dvorak_t *alt_uppercase, struct us_to_dvorak_t *alt_lowercase) {

    uint8_t registered_key;
    if (mod_state == MOD_BIT(KC_ALGR)) {
        registered_key = qf_process_mapping(mod_state, alt_uppercase, alt_lowercase);
    } else {
        registered_key = qf_process_mapping(mod_state, uppercase, lowercase);
    }
    set_mods(mod_state);
    return registered_key;
}


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        // QuantumFate
        case PD_1:
            static uint8_t registered_PD_1;
            static bool PD_1_registered;
            if (record->event.pressed) {
                uint8_t new_PD_1 = qf_process_press(mod_state, &QF_1, &QF_LBRC_CURVED, &QF_SPANISH_EXCLAMATION, &QF_EXPONENT_ONE);
                PD_1_registered = true;
                registered_PD_1 = new_PD_1;
                return false;
            } else {
                if (PD_1_registered) {
                    unregister_code(registered_PD_1);
                    PD_1_registered = false;
                    return false;
                }
            }
            return true;
        case PD_2:
            static uint8_t registered_PD_2;
            static bool PD_2_registered;
            if (record->event.pressed) {
                uint8_t new_PD_2 = qf_process_press(mod_state, &QF_2, &QF_RBRC_CURVED, &QF_SPANISH_QUESTION, &QF_EXPONENT_TWO);
                PD_2_registered = true;
                registered_PD_2 = new_PD_2;
                return false;
            } else {
                if (PD_2_registered) {
                    unregister_code(registered_PD_2);
                    PD_2_registered = false;
                    return false;
                }
            }
            return true;
        case PD_3:
            if (qf_block_altgr_shift(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_3;
            static bool PD_3_registered;
            if (record->event.pressed) {
                uint8_t new_PD_3 = qf_process_press(mod_state, &QF_3, &QF_RBRC_CURLY, &QF_NO_MAP, &QF_EXPONENT_THREE);
                PD_3_registered = true;
                registered_PD_3 = new_PD_3;
                return false;
            } else {
                if (PD_3_registered) {
                    unregister_code(registered_PD_3);
                    PD_3_registered = false;
                    return false;
                }
            }
            return false;
        case PD_4:
            static uint8_t registered_PD_4;
            static bool PD_4_registered;
            if (record->event.pressed) {
                uint8_t new_PD_4 = qf_process_press(mod_state, &QF_4, &QF_PLUS, &QF_DIVISION, &QF_BULLET_POINT);
                PD_4_registered = true;
                registered_PD_4 = new_PD_4;
                return false;
            } else {
                if (PD_4_registered) {
                    unregister_code(registered_PD_4);
                    PD_4_registered = false;
                    return false;
                }
            }
            return true;
        case PD_5:
            if (qf_block_altgr_shift(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_5;
            static bool PD_5_registered;
            if (record->event.pressed) {
                uint8_t new_PD_5 = qf_process_press(mod_state, &QF_5, &QF_LBRC_CURLY, &QF_NO_MAP, &QF_EURO);
                PD_5_registered = true;
                registered_PD_5 = new_PD_5;
                return false;
            } else {
                if (PD_5_registered) {
                    unregister_code(registered_PD_5);
                    PD_5_registered = false;
                    return false;
                }
            }
            return true;
        case PD_6:
            if (qf_block_altgr_shift(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_6;
            static bool PD_6_registered;
            if (record->event.pressed) {
                uint8_t new_PD_6 = qf_process_press(mod_state, &QF_6, &QF_RBRC_CORNER, &QF_NO_MAP, &QF_FR_LDOUBLE_QUOTE);
                PD_6_registered = true;
                registered_PD_6 = new_PD_6;
                return false;
            } else {
                if (PD_6_registered) {
                    unregister_code(registered_PD_6);
                    PD_6_registered = false;
                    return false;
                }
            }
            return true;
        case PD_7:
            if (qf_block_altgr_shift(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_7;
            static bool PD_7_registered;
            if (record->event.pressed) {
                uint8_t new_PD_7 = qf_process_press(mod_state, &QF_7, &QF_LBRC_CORNER, &QF_NO_MAP, &QF_FR_RDOUBLE_QUOTE);
                PD_7_registered = true;
                registered_PD_7 = new_PD_7;
                return false;
            } else {
                if (PD_7_registered) {
                    unregister_code(registered_PD_7);
                    PD_7_registered = false;
                    return false;
                }
            }
            return true;
        case PD_8:
            if (qf_block_altgr_shift(mod_state) || qf_block_altgr(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_8;
            static bool PD_8_registered;
            if (record->event.pressed) {
                uint8_t new_PD_8 = qf_process_press(mod_state, &QF_8, &QF_EXLAMATION_POINT, &QF_NO_MAP, &QF_NO_MAP);
                PD_8_registered = true;
                registered_PD_8 = new_PD_8;
                return false;
            } else {
                if (PD_8_registered) {
                    unregister_code(registered_PD_8);
                    PD_8_registered = false;
                    return false;
                }
            }
            return true;
        case PD_9:
            static uint8_t registered_PD_9;
            static bool PD_9_registered;
            if (record->event.pressed) {
                uint8_t new_PD_9 = qf_process_press(mod_state, &QF_9, &QF_EQUAL, &QF_FR_LSINGLE_QUOTE, &QF_MULTIPLY);
                PD_9_registered = true;
                registered_PD_9 = new_PD_9;
                return false;
            } else {
                if (PD_9_registered) {
                    unregister_code(registered_PD_9);
                    PD_9_registered = false;
                    return false;
                }
            }
            return true;
        case PD_0:
            if (qf_block_altgr(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_0;
            static bool PD_0_registered;
            if (record->event.pressed) {
                uint8_t new_PD_0 = qf_process_press(mod_state, &QF_0, &QF_ASTERISK, &QF_FR_RSINGLE_QUOTE, &QF_NO_MAP);
                PD_0_registered = true;
                registered_PD_0 = new_PD_0;
                return false;
            } else {
                if (PD_0_registered) {
                    unregister_code(registered_PD_0);
                    PD_0_registered = false;
                    return false;
                }
            }
            return true;
        case QF_QUOTE:
            if (qf_block_altgr_shift(mod_state) || qf_block_altgr(mod_state)) {
                return false;
            }
            static uint8_t registered_QF_QUOTE;
            static bool QF_QUOTE_registered;
            if (record->event.pressed) {
                uint8_t new_QF_QUOTE = qf_process_press(mod_state, &QF_SINGLE_QUOTE, &QF_DOUBLE_QUOTE, &QF_NO_MAP, &QF_NO_MAP);
                tap_code(KC_SPACE);
                QF_QUOTE_registered = true;
                registered_QF_QUOTE = new_QF_QUOTE;
                return false;
            } else {
                if (QF_QUOTE_registered) {
                    unregister_code(registered_QF_QUOTE);
                    QF_QUOTE_registered = false;
                    return false;
                }
            }
            return true;
        case QF_UML:
            if (qf_block_altgr_shift(mod_state) || qf_block_altgr(mod_state)) {
                return false;
            }
            static uint8_t registered_QF_UML;
            static bool QF_UML_registered;
            if (record->event.pressed) {
                uint8_t new_QF_UML = qf_process_press(mod_state, &QF_SINGLE_QUOTE, &QF_DOUBLE_QUOTE, &QF_NO_MAP, &QF_NO_MAP);
                QF_UML_registered = true;
                registered_QF_UML = new_QF_UML;
                return false;
            } else {
                if (QF_UML_registered) {
                    unregister_code(registered_QF_UML);
                    QF_UML_registered = false;
                    return false;
                }
            }
            return true;
        case PD_ND:
            if (qf_block_altgr_shift(mod_state) || qf_block_altgr(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_ND;
            static bool PD_ND_registered;
            if (record->event.pressed) {
                uint8_t new_PD_ND = qf_process_press(mod_state, &QF_PER, &QF_AND, &QF_NO_MAP, &QF_NO_MAP);
                PD_ND_registered = true;
                registered_PD_ND = new_PD_ND;
                return false;
            } else {
                if (PD_ND_registered) {
                    unregister_code(registered_PD_ND);
                    PD_ND_registered = false;
                    return false;
                }
            }
            return true;
        case PD_AT:
            if (qf_block_altgr_shift(mod_state) || qf_block_altgr(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_AT;
            static bool PD_AT_registered;
            if (record->event.pressed) {
                uint8_t new_PD_AT = qf_process_press(mod_state, &QF_ZIRK, &QF_AT, &QF_NO_MAP, &QF_NO_MAP);
                PD_AT_registered = true;
                registered_PD_AT = new_PD_AT;
                return false;
            } else {
                if (PD_AT_registered) {
                    unregister_code(registered_PD_AT);
                    PD_AT_registered = false;
                    return false;
                }
            }
            return true;
        case PD_HS:
            if (qf_block_altgr_shift(mod_state) || qf_block_altgr(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_HS;
            static bool PD_HS_registered;
            if (record->event.pressed) {
                uint8_t new_PD_HS = qf_process_press(mod_state, &QF_GRV, &QF_HASH, &QF_NO_MAP, &QF_NO_MAP);
                PD_HS_registered = true;
                registered_PD_HS = new_PD_HS;
                return false;
            } else {
                if (PD_HS_registered) {
                    unregister_code(registered_PD_HS);
                    PD_HS_registered = false;
                    return false;
                }
            }
            return true;
        case PD_DS:
            if (qf_block_altgr_shift(mod_state) || qf_block_altgr(mod_state)) {
                return false;
            }
            static uint8_t registered_PD_DS;
            static bool PD_DS_registered;
            if (record->event.pressed) {
                uint8_t new_PD_DS = qf_process_press(mod_state, &QF_TILDE, &QF_DS, &QF_NO_MAP, &QF_NO_MAP);
                PD_DS_registered = true;
                registered_PD_DS = new_PD_DS;
                return false;
            } else {
                if (PD_DS_registered) {
                    unregister_code(registered_PD_DS);
                    PD_DS_registered = false;
                    return false;
                }
            }
            return true;
    }

    return true;

}



    // PD_1(result)         : 1,          (,          ¡,          ¹
    // PD_1(desired press)  : shift-(,    nonshift-(, altShift-(, alt-(
    // PD_1(emulated press) : nonshift-1, shift-9,    alt-1,      altShift-1

    // PD_2(result)         : 2,          ),          ¿,          ²
    // PD_2(desired press)  : shift-(,    nonshift-), altShift-), alt-)
    // PD_2(emulated press) : nonshift-2, shift-0,    alt-/,      alt-2

    // PD_3(result)         : 3,          },                      ³
    // PD_3(desired press)  : shift-},    nonshift-}, -----,      alt-}
    // PD_3(emulated press) : nonshift-3, shift-],    -----,      alt-3

    // PD_4(result)         : 4,          +,          ÷,          ¤
    // PD_4(desired press)  : shift-+,    nonshift-+, altShift-+, alt-+
    // PD_4(emulated press) : nonshift-4, shift-=,    altShift-+, alt-4

    // PD_5(result)         : 5,          {,                      €
    // PD_5(desired press)  : shift-{,    nonshift-{, -----,      alt-{
    // PD_5(emulated press) : nonshift-5, shift-[,    -----,      alt-5

    // PD_6(result)         : 6,          ],                      »
    // PD_6(desired press)  : shift-],    nonshift-], -----,      alt-]
    // PD_6(emulated press) : nonshift-6, noneshift-],-----,      alt-]

    // PD_7(result)         : 7,          [,                      «
    // PD_7(desired press)  : shift-],    nonshift-[, -----,      alt-[
    // PD_7(emulated press) : nonshift-7, noneshift-[,-----,      alt-[

    // PD_8(result)         : 8,          !,
    // PD_8(desired press)  : shift-!,    nonshift-!, -----,      -----
    // PD_8(emulated press) : nonshift-8, shift-1,    -----,      -----

    // PD_9(result)         : 9,          =,          ‘,            ×
    // PD_9(desired press)  : shift-=,    nonshift-=, altShift-=,   alt-=
    // PD_9(emulated press) : nonshift-9, nonshift-=, alt-9,        alt-=

    // PD_0(result)         : 0,          *,          ’,
    // PD_0(desired press)  : shift-*,    nonshift-*, altShift-*, -----
    // PD_0(emulated press) : nonshift-0, shift-8,    alt-8,      -----

