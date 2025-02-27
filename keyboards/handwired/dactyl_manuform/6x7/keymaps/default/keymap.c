#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x7(
        // left hand                                                          right hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,           KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_BSLS,
        KC_CAPS, KC_HOME, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RBRC, KC_QUOT,
        KC_LSFT, KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,  KC_RSFT,
                                   KC_END,  KC_PSCR, KC_SPC,  KC_LGUI,        KC_UP,   KC_ENT,  KC_PGUP, KC_PGDN, 
                                   MO(_FN), KC_APP,  KC_LCTL,                          KC_RGHT, KC_DOWN, KC_LEFT 
    ),
    [_FN] = LAYOUT_6x7(
        // left hand                                                          right hand
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        KC_NUM,  _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LGUI, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,        KC_VOLU, KC_MPLY, _______, _______,
                                   _______, KC_INS,  _______,                          KC_MNXT, KC_VOLD, KC_MPRV
    )
};
