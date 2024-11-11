#include QMK_KEYBOARD_H

#define LY_NRML  0
#define LY_CRSR  1
#define LY_NUMB  2
#define LY_LFNC  3
#define LY_RFNC  4

#define LT_SPC  LT(LY_CRSR, KC_SPC)
#define LT_TAB  LT(LY_NUMB, KC_TAB) 
#define LT_LFN  LT(LY_LFNC, _______) 
#define LT_RFN  LT(LY_RFNC, _______) 

// #define MOUSEKEY_DELAY       1 
// #define MOUSEKEY_MOVE_DELTA  10
// #define MOUSEKEY_INTERVAL    2 
// #define MOUSEKEY_MAX_SPEED   70
// #define MOUSEKEY_TIME_TO_MAX 20

#define OSXBSLS A(KC_BSLS)
#define OSXREDO LSG(KC_Z)
#define OSXUNDO LGUI(KC_Z)
#define OSX_CUT LGUI(KC_X)
#define OSXCOPY LGUI(KC_C)
#define OSXPSTE LGUI(KC_V)

#define OSXHOME LCTL(KC_A)
#define OSX_END LCTL(KC_E)

#define IMEON   KC_LNG1
#define IMEOFF  KC_LNG2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer NORMAL JP:
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  ¥|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |
     * |------------------------------------------------------` Ent|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Ent|    |
     * |-----------------------------------------------------------|
     * |Shft   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  \| Up| Fn|
     * |-----------------------------------------------------------|
     * |Fn ||Alt|Cmd|IME|Bsp|  Space  |Ent|IME|Alt|Sft||Lft|Dwn|Rgh|
     * `-----------------------------------------------------------'
     */
    [LY_NRML] = LAYOUT_jp(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,  KC_EQL,  KC_INT3, KC_GRAVE,
        LT_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC, // KC_ENT
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_BSLS,  KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_INT1,  KC_UP,   LT_RFN,
        LT_LFN,  KC_LALT, KC_LGUI, IMEOFF, KC_BSPC,      LT_SPC,     KC_ENT,   IMEON,  KC_RALT,KC_RSFT, KC_LEFT,  KC_DOWN, KC_RGHT),


    /* Layer LY_CRSR: with SPACE
     * ,-----------------------------------------------------------.
     * |ESC|   |   |   |   |   |   |   |   |   |Hme|  -|  =|  |test|
     * |-----------------------------------------------------------|
     * |     |   |   |End|   |   |Redo|Pdn|Pup|   |   |   |   |    |
     * |------------------------------------------------------`    |
     * |Ctrl  |Hom|Spc|Del|   |   |Lft|Dwn| Up|Rgh|End|   |   |    |
     * |-----------------------------------------------------------|
     * |Shft|Undo|Cut|Copy|Past|Bsp|Ent|   |   |   |   |   | Up|   |
     * |-----------------------------------------------------------|
     * |Fn | Alt|Cmd|Mhen|Bsp|  Spc  |Ent|Henk|Alt|Sft||Lft|Dwn|Rgh|
     * `-----------------------------------------------------------'
     */
    [LY_CRSR] = LAYOUT_jp(
        KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSXHOME, KC_MINS, KC_EQL,  XXXXXXX, KC_C,
        XXXXXXX, XXXXXXX, XXXXXXX, OSX_END,  XXXXXXX, XXXXXXX, OSXREDO, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, OSXHOME, KC_SPC,  KC_DEL,  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, OSX_END,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, OSXUNDO, OSX_CUT, OSXCOPY, OSXPSTE, KC_BSPC, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,
        XXXXXXX,  KC_LALT, KC_LGUI, IMEOFF, KC_BSPC,      KC_SPC,      KC_ENT,  IMEON,  KC_RALT, KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT),


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
     * |  |  |   |   |   |   | Space |   |   |   |   |  |   |   |  |
     * `-----------------------------------------------------------'
     */
    [LY_NUMB] = LAYOUT_jp(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_EQL,  _______, KC_TAB,  _______, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH, _______,
        KC_LCTL, _______, KC_SPC,  KC_DEL,  _______, _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_PLUS, KC_MINS, _______, _______,
        KC_LSFT, _______, _______, KC_COMM, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______, _______, _______,
        _______, _______, _______, _______, _______,       KC_SPC,     _______, _______, _______, _______, _______, _______, _______),
    
    
    /* Layer LY_LFUNC:
     * ,--------------------------------------------------------------.
     * |ESC | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Ins|  BS|
     * |--------------------------------------------------------------|
     * |TAB |   |   |Ejc|   |WhlL|WhlD|WhlU|WhlR|   |   |   |   |     |
     * |---------------------------------------------------------`    |
     * |Ctrl |    |   |   |   |MosL|MosD|MosU|MosR|   |   |   |   |   |
     * |--------------------------------------------------------------|
     * |Shft |   |  |CAPS|   |Mos1|Mos2|Mos3|Mos4|   |   |BrDw|Up|BrUp|
     * |--------------------------------------------------------------|
     * |   |   |   |   |    |   | PLAY |   |   |   |  |  |Lft|Dwn|Rght|
     * `--------------------------------------------------------------'
     */
    // with LEFT FN
    [LY_LFNC] = LAYOUT_jp(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_INS, KC_BSPC,
        KC_TAB,  _______, _______, KC_EJCT, _______, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, KC_BRID, KC_VOLU, KC_BRIU,
        _______, _______, _______, _______, _______,       KC_BTN1,    _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT),

    /* Layer LY_RFUNC:
     * ,--------------------------------------------------------------.
     * |ESC | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Ins| Del|
     * |--------------------------------------------------------------|
     * |TAB |    |   |    |   |    |   |   |   |   |    |    |   |    |
     * |---------------------------------------------------------`    |
     * |Ctrl |    |   |   |   |    |    |    |    |   |   |   |   |   |
     * |--------------------------------------------------------------|
     * |Shft |   |  |    |   |    |    |    |    |   |   |    |  |    |
     * |--------------------------------------------------------------|
     * |   |   |   |   |    |   |      |   |   |   |  |  |   |   |    |
     * `--------------------------------------------------------------'
     */
    // with RIGHT FN
    [LY_RFNC] = LAYOUT_jp(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_INS, KC_DEL,
        KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT, KC_PGUP, _______,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_DOWN, KC_PGDN, _______, _______,
        _______, _______, _______, _______, _______,       _______,    _______, _______, _______, KC_RSFT, _______, _______, _______)
};
