#include QMK_KEYBOARD_H

#define _BL 0 // Base Layer
#define _FL 1 // Function Layer
#define _AL 2 // Alt Layer

enum custom_keycodes {
    U_LEGIT = SAFE_RANGE,
    U_TENT,
    EM_POOP,
    EM_XD,
    EM_ROFL,
    ALT_F4,
    ALT_F10,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        /* Mapping numpad to Fn + Right Ctrl + number */
        /* There's probably a better way to do this but naive implementation first, optimise later if necessary */
        case KC_F1:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_1) : unregister_code(KC_KP_1);
                return false;
            } else {
                return true;
            }
            break;
        case KC_F2:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_2) : unregister_code(KC_KP_2);
                return false;
            } else {
                return true;
            }
            break;
        case KC_F3:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_3) : unregister_code(KC_KP_3);
                return false;
            } else {
                return true;
            }
            break;
        case KC_F4:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_4) : unregister_code(KC_KP_4);
                return false;
            } else {
                return true;
            }
            break;
        case KC_F5:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_5) : unregister_code(KC_KP_5);
                return false;
            } else {
                return true;
            }
            break;
        case KC_F6:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_6) : unregister_code(KC_KP_6);
                return false;
            } else {
                return true;
            }
            break;
        case KC_F7:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_7) : unregister_code(KC_KP_7);
                return false;
            } else {
                return true;
            }
            break;
        case KC_F8:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_8) : unregister_code(KC_KP_8);
                return false;
            } else {
                return true;
            }
            break;
        case KC_F9:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_9) : unregister_code(KC_KP_9);
                return false;
            } else {
                return true;
            }
            break;
        case KC_F10:
            if (get_mods() & (MOD_BIT(KC_RCTL) == MOD_BIT(KC_RCTL))) {
                record->event.pressed ? register_code(KC_KP_0) : unregister_code(KC_KP_0);
                return false;
            } else {
                return true;
            }
            break;

        /* Pro Gamer macros */

        case U_LEGIT:
            if (record->event.pressed) SEND_STRING("\nseems legit \n");
            break;
        case U_TENT:
            if (record->event.pressed) SEND_STRING("\nI can't wait for the tent DLC so I can camp even harder \n");
            break;

        /* Emoji */

        case EM_POOP:
            if (record->event.pressed) send_unicode_string("💩");
            break;
        case EM_XD:
            if (record->event.pressed) send_unicode_string("😂");
            break;
        case EM_ROFL:
            if (record->event.pressed) send_unicode_string("🤣");
            break;

        /* Alt-layer keys */
        case ALT_F4:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_F4);
            } else {
                unregister_code(KC_F4);
                unregister_code(KC_LALT);            }
            break;
        case ALT_F10:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_F10);
            } else {
                unregister_code(KC_F10);
                unregister_code(KC_LALT);
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BL: (Base Layer) Default Layer
     * ,----------------------------------------------------------------.
     * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |F6  |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |F3  |
     * |----------------------------------------------------------------|
     * |~ `    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
     * |----------------------------------------------------------------|
     * |Ctrl|Alt |Win |        Space          |Win|Ctrl|FN |Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     */
    [_BL] = LAYOUT_65_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_F3,
        KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                    KC_RALT, KC_RCTL, MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap _FL: Function Layer
     * ,----------------------------------------------------------------.
     * |~ `| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Mute|
     * |----------------------------------------------------------------|
     * |RESET|   |Up |   |   |   |   |   |   |   |💩 |   |   |Tent |Hax |
     * |----------------------------------------------------------------|
     * |      |<- |Dn | ->|   |   |   |   |   |   |   |   |        | M< |
     * |----------------------------------------------------------------|
     * |UMODE   |   | 😂| 🤣|   |   |   |   |   |   |   |Play  | V+| M> |
     * |----------------------------------------------------------------|
     * |    |    |    |       _______         |   |   |    |Hom|V- |End |
     * `----------------------------------------------------------------'
     */
    [_FL] = LAYOUT_65_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_F6,
        RESET,   _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, EM_POOP, _______, _______, U_TENT,  U_LEGIT,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_MPRV,
        UC_MOD ,          _______, EM_XD  , EM_ROFL, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, KC_MNXT,
        _______, _______, _______,                            _______,                   _______, _______, KC_TRNS, KC_HOME, KC_VOLD, KC_END
    ),

    /* Keymap _AL: Alt Layer
     * ,----------------------------------------------------------------.
     * |~ `| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Mute|
     * |----------------------------------------------------------------|
     * |RESET|   |Up |   |   |   |   |   |   |   |💩 |   |   |Tent |Hax |
     * |----------------------------------------------------------------|
     * |      |<- |Dn | ->|   |   |   |   |   |   |   |   |        | M< |
     * |----------------------------------------------------------------|
     * |UMODE   |   | 😂| 🤣|   |   |   |   |   |   |   |Play  | V+| M> |
     * |----------------------------------------------------------------|
     * |    |    |    |       _______         |   |   |    |Hom|V- |End |
     * `----------------------------------------------------------------'
     */
    [_AL] = LAYOUT_65_ansi(
        _______, _______, _______, _______,  ALT_F4, _______, _______, _______, _______, _______, ALT_F10, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),
};


// [_LAYER] = LAYOUT_65_ansi(
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
//         _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//         _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
//     ),
