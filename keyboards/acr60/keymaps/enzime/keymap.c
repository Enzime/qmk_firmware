#include QMK_KEYBOARD_H

enum LAYERS {
  LAYER_DEFAULT = 0,
  LAYER_TRIPLE_SPACE,
  LAYER_CAPS_ESC,
  LAYER_FN,
  LAYER_LIGHTING,
};

enum CUSTOM_KEYCODES {
  TOG_TRIPLE_SPACE = SAFE_RANGE,
  TOG_CAPS_ESC,
  ENTER_LIGHTING,
  EXIT_FN,
  EXIT_LIGHTING,
};

// Fillers to make layering more clear
#define xxxxxx KC_NO
#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * ,-----------------------------------------------------------------------------------------.
 * | ` |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | PgUp | PgDn |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
 * |-----------------------------------------------------------------------------------------+
 * | Esc     |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  |  Up  |       |
 * |-----------------------------------------------------------------------------------------+
 * | LCtrl | LGUI | LAlt |  Backspace  | Fn |    Space    | Home | End | Left | Down | Right |
 * `-----------------------------------------------------------------------------------------'
 */
  [LAYER_DEFAULT] = LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_PGUP, KC_PGDN, \
    KC_TAB,       KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_LALT,      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,       \
    KC_LSFT, xxxxxx, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,       KC_DOT, KC_SLSH, KC_UP, xxxxxx, \
    KC_LCTL, KC_LGUI,       KC_PSCREEN, KC_BSPC,       TT(LAYER_FN),       KC_SPC,       KC_HOME, KC_END, KC_LEFT, KC_DOWN, KC_RIGHT \
  ),

  [LAYER_TRIPLE_SPACE] = LAYOUT(
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_BSPC, KC_BSPC, \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
    ______, ______, ______, KC_SPC, LT(LAYER_FN, KC_SPC), KC_SPC, ______, ______, ______, ______, ______ \
  ),

  [LAYER_CAPS_ESC] = LAYOUT(
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
    KC_ESC, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
    ______, ______, KC_LALT, ______, ______, ______, ______, ______, ______, ______, ______ \
  ),

  [LAYER_FN] = LAYOUT(
    xxxxxx, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, KC_INS,  KC_DEL, \
    xxxxxx, xxxxxx, xxxxxx, DEBUG, RESET, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, \
    TOG_CAPS_ESC, xxxxxx, xxxxxx, TO(LAYER_DEFAULT), xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, TO(LAYER_LIGHTING), xxxxxx, xxxxxx, xxxxxx, \
    xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, \
    xxxxxx, xxxxxx, xxxxxx, TOG_TRIPLE_SPACE, EXIT_FN, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx \
  ),

  [LAYER_LIGHTING] = LAYOUT(
    xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, \
    xxxxxx, RGB_HUD, RGB_HUI, xxxxxx, xxxxxx, RGB_TOG, xxxxxx, xxxxxx, xxxxxx, xxxxxx, RGB_RMOD, xxxxxx, xxxxxx, xxxxxx, \
    xxxxxx, RGB_SAD, RGB_SAI, RGB_M_P, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, \
    xxxxxx, xxxxxx, RGB_VAD, RGB_VAI, xxxxxx, xxxxxx, xxxxxx, RGB_MOD, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, \
    xxxxxx, xxxxxx, xxxxxx, xxxxxx, EXIT_LIGHTING, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx, xxxxxx \
  ),

  /*
  [_NORMAL] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, \
    KC_TAB,       KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_CAPS,      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,       \
    KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,       KC_DOT, KC_SLSH, KC_RSFT, xxxxxx, \
    KC_LCTL, KC_LGUI,       KC_LALT, KC_SPC,       TO(_FN),       KC_SPC,       KC_RALT, KC_APP, KC_RCTL, KC_RCTL, KC_GRV \
  ),
  */

  /*
  [_GAMING] = LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_PGUP, KC_PGDN, \
    KC_TAB,       KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_ESC,      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,       \
    KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,       KC_DOT, KC_SLSH, KC_UP, xxxxxx, \
    KC_LCTL, KC_LGUI,       KC_LALT, KC_SPC,       LT(_FN, KC_SPC),       KC_SPC,       KC_HOME, KC_END, KC_LEFT, KC_DOWN, KC_RIGHT \
  ),
  */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TOG_TRIPLE_SPACE:
      if (record->event.pressed) {
        layer_off(LAYER_FN);

        print("Toggling Triple Space Layer\n");
        layer_invert(LAYER_TRIPLE_SPACE);

        xprintf("Triple Space Layer state: %s\n", layer_state_is(LAYER_TRIPLE_SPACE) ? "on" : "off");

        layer_on(LAYER_FN);
      }

      return false;

    case TOG_CAPS_ESC:
      if (record->event.pressed) {
        layer_off(LAYER_FN);

        print("Toggling Caps-Esc Layer\n");
        layer_invert(LAYER_CAPS_ESC);

        xprintf("Caps-Esc Layer state: %s\n", layer_state_is(LAYER_CAPS_ESC) ? "on" : "off");

        layer_on(LAYER_FN);
      }

      return false;

    case ENTER_LIGHTING:
      if (record->event.pressed) {
        print("Entering Lighting Layer\n");
        layer_on(LAYER_LIGHTING);
      }

      return false;

    case EXIT_FN:
      if (record->event.pressed) {
        print("Exiting Fn Layer\n");
        layer_off(LAYER_FN);
      }

      return false;

    case EXIT_LIGHTING:
      if (record->event.pressed) {
        print("Exiting Lighting Layer\n");
        layer_off(LAYER_LIGHTING);
      }

      return false;

    case RESET:
      print("Entering DFU mode!\n");
      rgblight_sethsv_noeeprom(60, 255, 255);

    default:
      return true;
  }
}

rgblight_config_t rgblight_config;

void update_rgblight_state(uint32_t state) {
  rgblight_config.raw = eeconfig_read_rgblight();

  if (biton32(state) == LAYER_FN) {
    rgblight_sethsv_noeeprom(170, 255, 255);

    return;
  }
  else if (biton32(state) == LAYER_LIGHTING) {
      rgblight_disable_noeeprom();
      _delay_ms(100);
      rgblight_enable_noeeprom();

      return;
  }
  else {
    rgblight_sethsv_noeeprom(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
  }

  if (layer_state_cmp(state, LAYER_TRIPLE_SPACE)) {
    rgblight_sethsv_at(90, 255, 255, 11);
    rgblight_sethsv_at(90, 255, 255, 12);
    rgblight_sethsv_at(90, 255, 255, 13);
  }

  if (layer_state_cmp(state, LAYER_CAPS_ESC)) {
    rgblight_sethsv_at(20, 255, 255, 14);
    rgblight_sethsv_at(20, 255, 255, 0);
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  update_rgblight_state(state);

  return state;
}

void bootmagic_lite(void) {
  // The lite version of TMK's bootmagic.
  // 100% less potential for accidentally making the
  // keyboard do stupid things.

  // We need multiple scans because debouncing can't be turned off.
  matrix_scan();
  wait_ms(DEBOUNCING_DELAY);
  matrix_scan();

  // If Ctrl-R is held down on power up,
  // reset the EEPROM valid state and jump to bootloader.
  // Assumes Ctrl is at [4,0] and R is at [1,5].
  // This isn't very generalized, but we need something that doesn't
  // rely on user's keymaps in firmware or EEPROM.
  if ((matrix_get_row(1) & (1<<5)) && (matrix_get_row(4) & (1<<0))) {
    // Set the QMK EEPROM state as invalid.
    eeconfig_disable();
    // Change lights to indicate that we are in DFU mode
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(60, 255, 255);
    // Jump to bootloader.
    bootloader_jump();
  }
}

void matrix_init_user(void) {
  // do saviour like things
  bootmagic_lite();
}
