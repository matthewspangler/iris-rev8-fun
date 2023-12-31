// Copyright 2023 Matthew Spangler (@matthewspangler)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EE_HANDS

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
//#define SPLIT_LED_STATE_ENABLE
//#define SPLIT_MODS_ENABLE

#define BACKLIGHT_DEFAULT_LEVEL 4

#define RGBLIGHT_DEFAULT_HUE 85
#define RGBLIGHT_DEFAULT_SAT 255

#define RGBLIGHT_SPLIT

#define RGBLIGHT_LAYERS
#define RGBLIGHT_DISABLE_KEYCODES

#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT

#define RGB_MATRIX_LED_COUNT 68
#define RGBLED_NUM 68

// #define TAPPING_TOGGLE 1 // tap just once for TT() to toggle the layer
#define TAPPING_TERM 200

#define MOUSEKEY_DELAY 20
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_MAX_SPEED 10

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
