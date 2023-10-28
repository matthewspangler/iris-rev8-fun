// Copyright 2023 Matthew Spangler (@matthewspangler)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum my_layers {
    _QWERTY, // 0
    _FN, // 1
    _SYM, // 2
    _NAV, // 3
    _MOUSE, // 4
    _MEDIA, // 5
    _GAMING, // 6
    _MACRO, // 7
};

#define LAYER_CYCLE_START 0
#define LAYER_CYCLE_END  7

// SYM
#define LGU_GRV LGUI_T(KC_GRV)
#define LSF_QT LSFT_T(KC_QUOT)
#define RSF_MIN RSFT_T(KC_MINS)
#define RGU_EQL RGUI_T(KC_EQL)

// MISC
#define KC_CAPW LGUI(LSFT(KC_3)) // capture the whole screen on MacOS
#define KC_CAPP LGUI(LSFT(KC_5)) // capture portion of the screen on MacOS
#define GUI_DWN LGUI(KC_DOWN) // jump to the bottom of the document
#define GUI_UP LGUI(KC_UP) // jump to the top of the document

// LAYERS
#define MO_FN MO(_FN)
#define MO_NAV MO(_NAV)
#define MO_SYM MO(_SYM)
#define MO_MS MO(_MOUSE)
#define MO_MAC MO(_MACRO)
#define TO_QW TO(_QWERTY)
#define TO_FN TO(_FN)
#define TO_NAV TO(_NAV)
#define TO_SYM TO(_SYM)
#define TO_MS TO(_MOUSE)
#define TO_MED TO(_MEDIA)
#define TO_GAM TO(_GAMING)
#define TO_MAC TO(_MACRO)
#define FN_LBRC LT(_FN, KC_LBRC)
#define MS_RBRC LT(_MOUSE, KC_RBRC)

// Tap dance declarations
enum {
    LSCL, // left shift or caps lock
    TESC, // tilde or escape
    RAAL,
    LACL,
    AGUI,
    FNDN,
    MSUP,
};

tap_dance_action_t tap_dance_actions[] = {
    // Shift --> caps lock
    [LSCL] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    // Tilde --> escape
    [TESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
    // Right alt --> left alt
    [RAAL] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),
    // Left ctrl --> right ctrl
    [LACL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_RCTL),
    // KC_LGUI --> KC_RGUI
    [AGUI] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_RGUI),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       TD(TESC),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       TD(LSCL),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_N, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       TD(LACL),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, FN_LBRC,          MS_RBRC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      TD(AGUI),  TO_MAC,  KC_SPC,                    KC_SPC,   TO_FN,TD(RAAL)
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_FN] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______,    KC_1,    KC_2,    KC_3, KC_PPLS,                            _______, _______, _______, _______, KC_MINS,  KC_EQL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______,    KC_4,    KC_5,    KC_6, KC_PCMM,                            KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_DEL, KC_PSCR,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______,    KC_7,    KC_8,    KC_9, KC_PEQL,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_INS, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______,    KC_0,    KC_0, KC_PDOT, KC_PENT, _______,          _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______,   TO_QW, _______,                   _______,  TO_SYM, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),


    [_SYM] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LALT, KC_LCTL, LGU_GRV,  LSF_QT,  KC_DQT,                            KC_UNDS, RSF_MIN, RGU_EQL, KC_RCTL, KC_RALT, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LABK, KC_LPRN, KC_LCBR, KC_LBRC,KC_TILDE, _______,          _______, KC_PLUS, KC_RBRC, KC_RCBR, KC_RPRN, KC_RABK, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______,   TO_FN, _______,                   _______,  TO_NAV, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_NAV] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                            _______, KC_PGDN,   KC_UP, KC_PGUP, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LALT, KC_LCTL, KC_LGUI, KC_LSFT, _______,                            KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_END, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, GUI_DWN, _______,  GUI_UP, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______,  TO_SYM, _______,                   _______,   TO_MS, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_MOUSE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                            _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LALT, KC_LCTL, KC_LGUI, KC_LSFT, _______,                            KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_L, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______,  TO_NAV, _______,                   _______,  TO_MED, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_MEDIA] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______,   KC_F1,   KC_F2,   KC_F3, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______,   KC_F4,   KC_F5,   KC_F6, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______,   KC_F7,   KC_F8,   KC_F9, _______,                            _______, KC_BRIU, KC_VOLU, KC_MNXT, KC_MPLY, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______,  KC_F10,  KC_F11,  KC_F12, _______, _______,          _______, _______, KC_BRID, KC_VOLD, KC_MPRV, KC_MUTE, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______,   TO_MS, _______,                   _______,  TO_GAM, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_GAMING] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_N, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,          KC_RBRC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       KC_LGUI,  TO_MED,  KC_SPC,                    KC_SPC,  TO_MAC, KC_RALT
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_MACRO] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, QK_BOOT,  EE_CLR,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______,  TO_GAM, _______,                   _______,   TO_QW, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

};

// --------------------------
// RGB Lighting Configuration
// --------------------------

/*

LED index mapping:

          (31)              (32)              (33)                                    (67)              (66)              (65)
┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
│0       │1       │2       │3       │4       │5       │                          │39      │38      │37      │36      │35      │34      │
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
│11      │10      │9       │8       │7       │6       │                          │40      │41      │42      │43      │44      │45      │
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
│12      │13      │14      │15      │16      │17      │                          │51      │50      │49      │48      │47      │46      │
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
│23      │22      │21      │20      │19      │18      │27      │        │61      │52      │53      │54      │55      │56      │57      │
└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                               │24      │25      │26      │                 │60      │59      │58      │
                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
          (30)              (29)              (28)                                    (62)              (63)              (64)

*/

const rgblight_segment_t PROGMEM QWERTY_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {0, 6, HSV_PURPLE},
    {6, 6, HSV_PURPLE},
    {12, 6, HSV_PURPLE},
    {18, 6, HSV_PURPLE},
    {24, 1, HSV_PURPLE},
    {25, 1, HSV_PURPLE},
    {26, 1, HSV_PURPLE},
    {27, 1, HSV_PURPLE},
    {28, 3, HSV_PURPLE}, // underglow
    {31, 3, HSV_PURPLE}, // underglow
    // right side
    {34, 6, HSV_PURPLE},
    {40, 6, HSV_PURPLE},
    {46, 6, HSV_PURPLE},
    {52, 6, HSV_PURPLE},
    {58, 1, HSV_PURPLE},
    {59, 1, HSV_PURPLE},
    {60, 1, HSV_PURPLE},
    {61, 1, HSV_PURPLE},
    {62, 3, HSV_PURPLE}, // underglow
    {65, 3, HSV_PURPLE} // underglow
);

const rgblight_segment_t PROGMEM FN_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {0, 6, HSV_RED},
    {6, 6, HSV_RED},
    {12, 6, HSV_RED},
    {18, 6, HSV_RED},
    {24, 4, HSV_RED},
    {28, 3, HSV_RED}, // underglow
    {31, 3, HSV_RED}, // underglow
    // right side
    {34, 6, HSV_RED},
    {40, 6, HSV_RED},
    {46, 6, HSV_RED},
    {52, 6, HSV_RED},
    {58, 1, HSV_RED},
    {59, 1, HSV_RED},
    {60, 2, HSV_RED},
    {62, 3, HSV_RED}, // underglow
    {65, 3, HSV_RED} // underglow
);

const rgblight_segment_t PROGMEM SYM_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left sidfile:///var/home/palebluedot/Coding/iris-rev8-fun/build-volume/build-output/keebio_iris_rev8_matthewspangler.uf2e
    {0, 6, HSV_AZURE},
    {6, 6, HSV_AZURE},
    {12, 6, HSV_AZURE},
    {18, 6, HSV_AZURE},
    {24, 4, HSV_AZURE},
    {28, 3, HSV_AZURE}, // underglow
    {31, 3, HSV_AZURE}, // underglow
    // right side
    {34, 6, HSV_AZURE},
    {40, 6, HSV_AZURE},
    {46, 6, HSV_AZURE},
    {52, 6, HSV_AZURE},
    {58, 2, HSV_AZURE},
    {60, 1, HSV_AZURE},
    {61, 1, HSV_AZURE},
    {62, 3, HSV_AZURE}, // underglow
    {65, 3, HSV_AZURE} // underglow
);

const rgblight_segment_t PROGMEM NAV_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {0, 6, HSV_GREEN},
    {6, 6, HSV_GREEN},
    {12, 6, HSV_GREEN},
    {18, 6, HSV_GREEN},
    {24, 1, HSV_GREEN},
    {25, 1, HSV_GREEN},
    {26, 2, HSV_GREEN},
    {28, 3, HSV_GREEN}, // underglow
    {31, 3, HSV_GREEN}, // underglow
    // right side
    {34, 6, HSV_GREEN},
    {40, 6, HSV_GREEN},
    {46, 1, HSV_GREEN},
    {47, 5, HSV_GREEN},
    {52, 6, HSV_GREEN},
    {58, 4, HSV_GREEN},
    {62, 3, HSV_GREEN}, // underglow
    {65, 3, HSV_GREEN} // underglow
);

const rgblight_segment_t PROGMEM MOUSE_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {0, 6, HSV_ORANGE},
    {6, 6, HSV_ORANGE},
    {12, 6, HSV_ORANGE},
    {18, 6, HSV_ORANGE},
    {24, 2, HSV_ORANGE},
    {26, 1, HSV_ORANGE},
    {27, 1, HSV_ORANGE},
    {28, 3, HSV_ORANGE}, // underglow
    {31, 3, HSV_ORANGE}, // underglow
    // right side
    {34, 6, HSV_ORANGE},
    {40, 6, HSV_ORANGE},
    {46, 6, HSV_ORANGE},
    {52, 6, HSV_ORANGE},
    {58, 4, HSV_ORANGE},
    {62, 3, HSV_ORANGE}, // underglow
    {65, 3, HSV_ORANGE} // underglow
);

const rgblight_segment_t PROGMEM MEDIA_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {0, 6, HSV_YELLOW},
    {6, 6, HSV_YELLOW},
    {12, 6, HSV_YELLOW},
    {18, 6, HSV_YELLOW},
    {24, 2, HSV_YELLOW},
    {26, 1, HSV_YELLOW},
    {27, 1, HSV_YELLOW},
    {28, 3, HSV_YELLOW}, // underglow
    {31, 3, HSV_YELLOW}, // underglow
    // right side
    {34, 6, HSV_YELLOW},
    {40, 6, HSV_YELLOW},
    {46, 6, HSV_YELLOW},
    {52, 6, HSV_YELLOW},
    {58, 4, HSV_YELLOW},
    {62, 3, HSV_YELLOW}, // underglow
    {65, 3, HSV_YELLOW} // underglow
);

const rgblight_segment_t PROGMEM GAMING_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {0, 6, HSV_BLUE},
    {6, 6, HSV_BLUE},
    {12, 6, HSV_BLUE},
    {18, 6, HSV_BLUE},
    {24, 2, HSV_BLUE},
    {26, 1, HSV_BLUE},
    {27, 1, HSV_BLUE},
    {28, 3, HSV_BLUE}, // underglow
    {31, 3, HSV_BLUE}, // underglow
    // right side
    {34, 6, HSV_BLUE},
    {40, 6, HSV_BLUE},
    {46, 6, HSV_BLUE},
    {52, 6, HSV_BLUE},
    {58, 4, HSV_BLUE},
    {62, 3, HSV_BLUE}, // underglow
    {65, 3, HSV_BLUE} // underglow
);


const rgblight_segment_t* const PROGMEM MY_LIGHT_LAYERS[] = RGBLIGHT_LAYERS_LIST(
    QWERTY_LIGHT_LAYER,
    FN_LIGHT_LAYER,
    SYM_LIGHT_LAYER,
    NAV_LIGHT_LAYER,
    MOUSE_LIGHT_LAYER,
    MEDIA_LIGHT_LAYER,
    GAMING_LIGHT_LAYER
);

void keyboard_post_init_user(void) {
    rgblight_layers = MY_LIGHT_LAYERS;
}


layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_FN, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(_SYM, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_MOUSE, layer_state_cmp(state, _MOUSE));
    rgblight_set_layer_state(_MEDIA, layer_state_cmp(state, _MEDIA));
    rgblight_set_layer_state(_GAMING, layer_state_cmp(state, _GAMING));

    return state;
}
