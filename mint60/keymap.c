/* Copyright 2018 Eucalyn
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
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

extern keymap_config_t keymap_config;


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
  RGBRST = SAFE_RANGE
};


// written by tecokimura
#define LY_NORMAL 0
#define LY_CURSOR 1
#define LY_MOUSE  2
#define LY_NUMBER 3
#define LY_FUNC   4

#define LT_CRSR  LT(LY_CURSOR, KC_SPC)
#define LT_MOUS  LT(LY_MOUSE,  KC_ESC) 
#define LT_NUMB  LT(LY_NUMBER, KC_TAB) 
#define LT_FUNC  LT(LY_FUNC,   _______) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_NORMAL] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,  \
    LT_NUMB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  \
    KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_ENT,   \
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_Q,      KC_UP,  KC_RSFT,   \
    LT_MOUS,  KC_LGUI, KC_LALT,  KC_BSPC,          KC_SPC,      LT_CRSR,  KC_ENT,  LALT(KC_GRV),               KC_LEFT,KC_DOWN,KC_RGHT \
  ),

  [LY_CURSOR] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_HOME,  KC_MINS,  KC_EQL,    KC_DEL, \
    RGB_TOG,   _______,  KC_Q, KC_END, RGB_VAI, XXXXXXX,       KC_HOME, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX,     KC_HOME, KC_SPC, KC_DEL, XXXXXXX, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END, XXXXXXX,        KC_ENT, \
    _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,   KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_PGUP, KC_RSFT, \
    XXXXXXX,   _______,    _______,    _______,    XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_END \
  ),

  [LY_MOUSE] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL, \
    _______,   RGBRST,  RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_LCTL,     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,        XXXXXXX, \
    KC_LSFT,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, _______, KC_PGUP, _______, \
    XXXXXXX,   _______,    _______,    _______,    XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_END \
  ),

  [LY_NUMBER] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL, \
    KC_TAB,   RGBRST,  RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,   XXXXXXX,  KC_7,    KC_8,    KC_9,    KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX,     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,   XXXXXXX,   KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ASTR,        XXXXXXX, \
    _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______, KC_PGUP, _______, \
    XXXXXXX,   _______,    _______,    _______,    XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_END \
  ),

  [LY_FUNC] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL, \
    RGB_TOG,   RGBRST,  RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX,     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, \
    _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_PGUP, _______, \
    XXXXXXX,   _______,    _______,    _______,    XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_END \
  )};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}
