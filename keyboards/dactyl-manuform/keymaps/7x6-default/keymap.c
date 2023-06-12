#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FN 1

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP_7x6(
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
        KC_TAB, KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_CAPS, KC_HOME, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_END, KC_PSCR, KC_SPC, MO(_FN), KC_APP, 
        KC_LCTRL, KC_LALT,
        // right hand
        KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_BSLS,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_RBRC, KC_QUOT,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_DEL, KC_RSFT,
        KC_DOWN, KC_UP, KC_ENT, KC_PGUP, KC_PGDN, 
        KC_LEFT, KC_RGHT),
    [_FN] = KEYMAP_7x6(
        // left hand
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, 
        _______, _______,
        // right hand
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        KC_VOLD, KC_VOLU, KC_MPLY, KC_MPRV, KC_MNXT, 
        _______, _______),
};

void persistant_default_layer_set(uint16_t default_layer)
{
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
