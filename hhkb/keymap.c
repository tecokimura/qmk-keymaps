#include QMK_KEYBOARD_H

#include "keymap_jp.h"

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer NORMAL JP:
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9| 10|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |
     * |------------------------------------------------------` Ent|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Ent|    |
     * |-----------------------------------------------------------|
     * |Shft   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  `| Up| Fn|
     * |-----------------------------------------------------------|
     * |Fn ||Alt|Cmd|Mhen|Bsp|  Spc  |Ent|Henk|Alt|Sft||Lft|Dwn|Rgh|
     * `-----------------------------------------------------------'
     */
    [LY_NRML] = LAYOUT_JP(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_GRAVE,
        LT_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC, // KC_ENT
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENT,  KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RO,    KC_UP,   LT_RFN,
        LT_LFN,  KC_LALT, KC_LGUI, KC_MHEN, KC_BSPC,      LT_SPC,     KC_ENT,  KC_HENK, KC_RALT,KC_RSFT, KC_LEFT,  KC_DOWN, KC_RGHT),


    /* Layer LY_CRSR: with SPACE
     * ,-----------------------------------------------------------.
     * |`  |   |   |   |   |   |   |   |   |   |Hme|  -|  =|   |  `|
     * |-----------------------------------------------------------|
     * |     |   |   |End|   |   |Hom|Pdn|Pup|   |   |   |   |     |
     * |------------------------------------------------------`    |
     * |Ctrl  |Hom|Spc|Del|   |   |Lft|Dwn| Up|Rgh|End|   |   |    |
     * |-----------------------------------------------------------|
     * |Shft   |   |   |   |   |Bsp|Ent|   |   |   |   |   | Up|Sft|
     * |-----------------------------------------------------------|
     * |Fn ||Alt|Cmd|Mhen|Bsp|  Spc  |Ent|Henk|Alt|Sft||Lft|Dwn|Rgh|
     * `-----------------------------------------------------------'
     */
    [LY_CRSR] = LAYOUT_JP(
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_MINS, KC_EQL,  _______, KC_GRAVE,
        _______, _______, _______, KC_END,  _______, _______, KC_HOME, KC_PGDN, KC_PGUP, _______, _______, _______, _______,
        KC_LCTL, KC_HOME, KC_SPC,  KC_DEL,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  _______, _______, _______,
        KC_LSFT, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,KC_BSPC, KC_ENT,  _______, _______, _______, _______, _______, KC_UP,   KC_RSFT,
        _______,  KC_LALT, KC_LGUI, KC_MHEN, KC_BSPC,      KC_SPC,      KC_ENT,  KC_HENK, KC_RALT, KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT),


    /* Layer LY_NUMB: with TAB
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|
     * |     |   |   |Eql|   |   |   |  7|  8|  9|Ast|Slh|   |     |
     * |------------------------------------------------------`    |
     * |Ctrl  |Hom|Spc|Del|   |   |  0|  4|  5|  6|Pls|Min|   |    |
     * |-----------------------------------------------------------|
     * |Shft   |   |   |  ,|   |   |  0|  1|  2|  3|Slh|   |   |   |
     * |-----------------------------------------------------------|
     * |   ||   |   |    |   | Space |   |    |   |   ||   |   |   |
     * `-----------------------------------------------------------'
     */
    [LY_NUMB] = LAYOUT_JP(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_EQL,  _______, KC_TAB,  _______, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH, _______,
        KC_LCTL, _______, KC_SPC,  KC_DEL,  _______, _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_PLUS, KC_MINS, _______, _______,
        KC_LSFT, _______, _______, KC_COMM, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______, _______, _______,
        _______, _______, _______, _______, _______,       KC_SPC,     _______, _______, _______, _______, _______, _______, _______),
    
    
    /* Layer LY_XXXX: with ESC
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|
     * |TAB  |   |   |Eql|   |   |   |  7|  8|  9|Ast|Slh|   |     |
     * |------------------------------------------------------`    |
     * |Ctrl  |Hom|Spc|Del|   |   |  0|  4|  5|  6|Pls|Min|   |    |
     * |-----------------------------------------------------------|
     * |Shft   |   |   |  ,|   |   |  0|  1|  2|  3|Slh|   |   |   |
     * |-----------------------------------------------------------|
     * |   ||   |   |    |   | Space |   |    |   |   ||   |   |   |
     * `-----------------------------------------------------------'
     */
    // with LEFT FN
    [LY_LFNC] = LAYOUT_JP(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_INS, KC_DEL,
        KC_TAB,  _______, _______, KC_EJCT, _______, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______,
        KC_LSFT, _______, _______, KC_CAPS, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, KC_BRID, KC_VOLU, KC_BRIU,
        _______, _______, _______, _______, _______,       KC_MPLY,    _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT),

    // with RIGHT FN
    [LY_RFNC] = LAYOUT_JP(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_INS, KC_DEL,
        KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_DOWN, _______, _______, _______,
        _______, _______, _______, _______, _______,       _______,    _______, _______, _______, KC_RSFT, _______, _______, _______)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t macro_id, uint8_t opt)
{
    return MACRO_NONE;
}

const uint16_t PROGMEM fn_actions[] = {

};
