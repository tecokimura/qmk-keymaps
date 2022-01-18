// なんか壊れた・・・右側が書き込みできてない？
// 左側はあってるのか確認する
// 右側をマスターにして書き込みむか、
// マスターを都度切り替えて２回Flashするとうまく行った
//
// https://github.com/qmk/qmk_firmware/blob/master/quantum/keycode.h
// https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_jp.h

/* Copyright 2020 yushakobo
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
#include "keymap_jp.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  LY_NRML,
  LY_CRSR,
  LY_NUMB,
  LY_LFNC,
  LY_RFNC
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  EISU,
  KANA,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)


//------
// Kimura's original define
#define LY_NRML  0
#define LY_CRSR  1
#define LY_NUMB  2
#define LY_LFNC  3
#define LY_RFNC  4

#define LT_SPC  LT(LY_CRSR, KC_SPC)
#define LT_TAB  LT(LY_NUMB, KC_TAB) 
#define LT_LFN  LT(LY_LFNC, _______) 
#define LT_RFN  LT(LY_RFNC, _______) 

#define MOUSEKEY_DELAY       1 
#define MOUSEKEY_MOVE_DELTA  10
#define MOUSEKEY_INTERVAL    2 
#define MOUSEKEY_MAX_SPEED   70
#define MOUSEKEY_TIME_TO_MAX 20
//=========


//#if MATRIX_ROWS == 10 // HELIX_ROWS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |   -  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | LTab |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   (  |   )  |   N  |   M  |   ,  |   .  |   /  |   \  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | LFN  | Alt  | GUI  | 無変 |  BS  | LSpc |   [  |   ]  | LSpc | Enter| 変換 |  Alt | 全半 | RFn  |
   * `-------------------------------------------------------------------------------------------------'
   */
  [LY_NRML] = LAYOUT(
      KC_ESC,  KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,   KC_8,    KC_9,   KC_0,    JP_MINS,
      LT_TAB,  KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    JP_AT,
      KC_LCTL, KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,   JP_LPRN, JP_RPRN, KC_N,    KC_M,   KC_COMM, KC_DOT, JP_SLSH, JP_BSLS,
      LT_LFN,  KC_LALT,KC_LGUI,KC_MHEN, KC_BSPC, LT_SPC, JP_LBRC, JP_RBRC, LT_SPC, KC_ENT,  KC_HENK, KC_RALT,JP_ZKHK, LT_RFN 
    ),

  /* Colemak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | 全半 |      |      |      |      |      |             |      |      |      |      | Home |   `  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |  End |      |      |             | Home |   L  |   U  |      |   ;  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl | Home | Space|  Del |      |      |             | Left |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift| Undo |  Cut | Copy | Paste| Bksp |   [  |   ]  | Enter|   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | Alt  | GUI  | 無変 | Bksp |      |   <  |   >  |      | KANA | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [LY_CRSR] = LAYOUT(
      JP_ZKHK, _______, _______, _______, _______,  _______,                   KC_CAPS, _______, _______, _______, KC_HOME, JP_GRV,
      _______, _______, _______, KC_END,  _______,  _______,                   KC_HOME, KC_PGDN, KC_PGUP, _______, _______, _______,
      KC_LCTL, KC_HOME, KC_SPC,  KC_DEL,  _______,  _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  _______,
      KC_LSFT, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  KC_BSPC, JP_LPRN, JP_RPRN, KC_ENT,  _______, _______, _______, _______, _______,
      _______, KC_LALT, KC_LGUI, KC_MHEN, KC_BSPC,  _______, JP_LABK, JP_RABK, _______, KC_ENT,  KC_HENK, KC_RALT, _______, _______
    ),

  /* Dvorak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |   [  |   ]  |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [LY_NUMB] = LAYOUT(
      KC_ESC,  _______, _______, _______, _______, _______,                   _______, KC_7,    KC_8,    KC_9,    _______, JP_BSLS,
      _______, _______, _______, JP_EQL,  _______, _______,                   _______, KC_4,    KC_5,    KC_6,    _______, _______,
      KC_LCTL, _______, KC_SPC,  KC_DEL,  _______, _______,                   KC_0,    KC_1,    KC_2,    KC_3,    JP_LPRN, JP_RPRN,
      KC_LSFT, _______, _______, KC_COMM, _______, _______, _______, _______, KC_BSPC, JP_PLUS, JP_MINS, JP_ASTR, JP_SLSH, JP_PERC,
      _______, KC_LALT, KC_LGUI, KC_MHEN, KC_BSPC, KC_SPC,  _______, _______, KC_SPC,  KC_ENT,  KC_HENK, KC_RALT, KC_SLSH, JP_EQL 
   ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |  (   |   )  |  F12 |      |      | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [LY_LFNC] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      KC_TAB,  _______, _______, KC_EJCT, _______, KC_TAB,                    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
      KC_LCTL, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
      KC_LSFT, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD, _______, KC_LPRN, KC_RPRN, KC_BTN1, KC_BTN2, KC_BTN3, KC_BRID, KC_VOLU, KC_BRIU,
      _______, _______, _______, _______, _______, KC_MPLY, RGB_MOD, RGB_TOG, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),


  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |  (   |   )  |  F12 |      |      | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [LY_RFNC] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )

};

//#elif MATRIX_ROWS == 8 // HELIX_ROWS == 4
// 
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 
//   /* Qwerty
//    * ,-----------------------------------------.             ,-----------------------------------------.
//    * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
//    * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
//    * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
//    * `-------------------------------------------------------------------------------------------------'
//    */
//   [_QWERTY] = LAYOUT(
//       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//       KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//       ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, EISU,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   KANA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
//       ),
// 
//   /* Colemak
//    * ,-----------------------------------------.             ,-----------------------------------------.
//    * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * | Ctrl |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  '   |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   K  |   M  |   ,  |   .  |   /  |Enter |
//    * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
//    * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
//    * `-------------------------------------------------------------------------------------------------'
//    */
//   [_COLEMAK] = LAYOUT(
//       KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
//       KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
//       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//       ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, EISU,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   KANA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
//       ),
// 
//   /* Dvorak
//    * ,-----------------------------------------.             ,-----------------------------------------.
//    * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Del  |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * | Ctrl |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * | Shift|   ;  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  |Enter |
//    * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
//    * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
//    * `-------------------------------------------------------------------------------------------------'
//    */
//   [_DVORAK] = LAYOUT(
//       KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL,
//       KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
//       KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
//       ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, EISU,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   KANA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
//       ),
// 
//   /* Lower
//    * ,-----------------------------------------.             ,-----------------------------------------.
//    * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      |      | Home | End  |      |
//    * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
//    * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
//    * `-------------------------------------------------------------------------------------------------'
//    */
//   [_LOWER] = LAYOUT(
//       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
//       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
//       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, _______, KC_HOME, KC_END,  _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
//       ),
// 
//   /* Raise
//    * ,-----------------------------------------.             ,-----------------------------------------.
//    * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      |      |PageDn|PageUp|      |
//    * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
//    * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
//    * `-------------------------------------------------------------------------------------------------'
//    */
//   [_RAISE] = LAYOUT(
//       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
//       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
//       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, _______, KC_PGDN, KC_PGUP, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
//       ),
// 
//   /* Adjust (Lower + Raise)
//    * ,-----------------------------------------.             ,-----------------------------------------.
//    * |      | Reset|RGBRST|      |      |      |             |      |      |      |      |      |  Del |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * |      |      |      |Aud on|Audoff| Mac  |             | Win  |Qwerty|Colemk|Dvorak|      |      |
//    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
//    * |      |      |      |      |      |      |             |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
//    * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
//    * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
//    * `-------------------------------------------------------------------------------------------------'
//    */
//   [_ADJUST] =  LAYOUT(
//       _______, RESET,    RGBRST, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,
//       _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
//       _______, _______, _______, _______, _______, _______,                   _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD
//       )
// };
// 
//#else
//#error "undefined keymaps"
//#endif


#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /*
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      return false;
      break;
    case EISU:
      if (record->event.pressed) {
        if (is_mac_mode()) {
          register_code(KC_LANG2);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if (is_mac_mode()) {
          register_code(KC_LANG1);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      break;
  }
  */
  return true;
}

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_get_mode();
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
