#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _NUM, // Similar to FN layer but ONLY numpad stuff!
    _FN,
    _AUX
};

// Custom keycodes, usually used for Macros and such
enum custom_keycodes {
  MAC_COPY = SAFE_RANGE,
  MAC_CUT,
  MAC_PASTE,
  MAC_UNDO,
  MAC_000,
  MAC_ALTF4,
  MAC_ONEP,
  MC_ATAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base layer
   */
  [_BASE] = LAYOUT(

  //,--0-----+--1--------+--2--------+--3---------+---4------+--5------+--6------+--7--------+--8------+--9---------+--10------+--11------+--12-------+--13-------+--14----------+
    KC_ESC,     KC_1,       KC_2,      KC_3,        KC_4,     KC_5,     KC_BSPC,   KC_6,       KC_7,     KC_8,       KC_9,       KC_0,      KC_LBRC,    KC_RBRC,   TG(_NUM),
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TAB,     KC_QUOT,    KC_COMM,   KC_DOT,      KC_P,     KC_Y,                KC_F,       KC_G,     KC_C,       KC_R,       KC_L,      KC_SLSH,    KC_EQL,    KC_DEL,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_LSFT,    KC_A,       KC_O,      KC_E,        KC_U,     KC_I,     KC_ENT,    KC_D,       KC_H,     KC_T,       KC_N,       KC_S,      KC_MINS,    KC_RSFT,   LT(_AUX, KC_F1),
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
                KC_SCLN,    KC_Q,      KC_J,        KC_K,     KC_X,                KC_B,       KC_M,     KC_W,       KC_V,       KC_Z,      KC_BSLS,               LT(_FN, KC_F2),
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_LCTL,    KC_LGUI,    KC_LALT,   MO(_FN),     KC_SPC,                                    KC_SPC,   KC_GRAVE,   KC_HOME,    KC_UP,     KC_END,     KC_RCTL,   KC_PGUP,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
                                                                                                         KC_RALT,    KC_LEFT,    KC_DOWN,   KC_RGHT,               KC_PGDN
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+---------------------------------------
  ),

// When NUM key is tapped (toggle switch)
[_NUM] = LAYOUT(

  //,--0-----+--1--------+--2--------+--3---------+---4------+--5------+--6------+--7--------+--8------+--9---------+--10------+--11------+--12-------+--13-------+--14----------+
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,             KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_PEQL,   KC_PSLS,   KC_PAST,    KC_PMNS,    KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_DOWN,  KC_TRNS,     KC_P7,     KC_P8,     KC_P9,      KC_PPLS,    KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
               KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,             KC_LEFT,   KC_UP,    KC_RGHT,     KC_P4,     KC_P5,     KC_P6,                  KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,         KC_TRNS,                           KC_TRNS,       KC_TRNS,     KC_P1,     KC_P2,     KC_P3,      KC_PENT,    KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
                                                                                                         KC_TRNS,     KC_P0,     MAC_000,   KC_PDOT,                KC_TRNS
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+---------------------------------------

),

/*
NOTES:
https://docs.qmk.fm/#/feature_layers

AUX Key is F1 (no bump). Hold to activate AUX layer. Tap for F1.
F2 is alternate Fn Key (has bump). Hold for Fn layer, Tap for F2.

AUX + R = Bootloader Mode

Fn + Y = Print Screen
Fn + A = Undo
Fn + O = Cut
Fn + E = Copy
Fn + U = Paste

Fn + Esc = Grave with auto shift (hold for tilde)

Fn + C = Pause/Break, which should be the Compose Key in your Desktop Env.
*/

/*
Fn, when Fn or F2 is held
 */
[_FN] = LAYOUT(

  //,--0-----+--1--------+--2--------+--3---------+---4------+--5------+--6------+--7--------+--8------+--9---------+--10------+--11------+--12-------+--13-------+--14----------+
    KC_GRAVE,     KC_F1,     KC_F2,      KC_F3,      KC_F4,     KC_F5,    KC_VOLU,   KC_F6,    KC_F7,    KC_F8,       KC_F9,     KC_F10,    KC_F11,     KC_F12,     KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    MC_ATAB,     KC_DEL,    KC_TRNS,    MAC_ALTF4,  MAC_ONEP,   KC_PSCR,             KC_NUM,   KC_TRNS,  KC_PAUS,     KC_PEQL,   KC_PSLS,   KC_PAST,    KC_PMNS,    KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,    MAC_UNDO,   MAC_CUT,   MAC_COPY,   MAC_PASTE,  KC_TRNS,  KC_VOLD,  KC_TRNS,    KC_TRNS,  KC_TRNS,     KC_P7,     KC_P8,     KC_P9,      KC_PPLS,    KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
                  KC_NO,     KC_NO,    KC_NO,       KC_NO,     KC_NO,               KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_P4,     KC_P5,     KC_P6,                  KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,      KC_MPLY, /* pause */                 KC_MUTE,       KC_APP,      KC_P1,     KC_P2,     KC_P3,      KC_PENT,    KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
                                                                                                         KC_TRNS,     KC_P0,     MAC_000,   KC_PDOT,                KC_TRNS
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+---------------------------------------

),

// When F1 key is held
[_AUX] = LAYOUT(

  //,--0-----+--1--------+--2--------+--3---------+---4------+--5------+--6------+--7--------+--8------+--9---------+--10------+--11------+--12-------+--13-------+--14----------+
    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,            KC_TRNS,     KC_TRNS,  KC_TRNS,     QK_BOOT,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
                KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,            KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,                 KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,                                    KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
                                                                                                         KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,                 KC_TRNS
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+---------------------------------------

)
/*
[_ALSO] = LAYOUT(
  // all TRNS layer, for future copy/paste
  //,--0-----+--1--------+--2--------+--3---------+---4------+--5------+--6------+--7--------+--8------+--9---------+--10------+--11------+--12-------+--13-------+--14----------+
    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,            KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
                KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,            KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,                 KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,                                    KC_TRNS,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+--------.
                                                                                                         KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,                 KC_TRNS
  //,--------+-----------+-----------+------------+----------+---------+---------+-----------+---------+------------+----------+----------+---------------------------------------

)
*/

};

/*
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MAC_000:
        if (record->event.pressed) {
            // when keycode MAC_000 is pressed
            SEND_STRING("000");
        }
        break;

    case MAC_COPY:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_LCTL(SS_TAP(X_INS))); // copy
        }
        break;

    case MAC_CUT:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_LSFT(SS_TAP(X_DEL)));
        }
        break;

    case MAC_PASTE:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_LSFT(SS_TAP(X_INS)));
        }
        break;

    case MAC_UNDO:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_LCTL("z")); // Ctrl Z undo
        }
        break;

    case MAC_ALTF4:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_DOWN(X_LALT));
            SEND_STRING(SS_TAP(X_F4));
            SEND_STRING(SS_UP(X_LALT));
        }
        break;

    case MAC_ONEP:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_DOWN(X_LALT));
            SEND_STRING(SS_DOWN(X_LSFT));
            SEND_STRING(SS_TAP(X_F8));
            SEND_STRING(SS_UP(X_LSFT));
            SEND_STRING(SS_UP(X_LALT));
        }
        break;

    case MC_ATAB:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
        }
        break;


    }
    return true;
};

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    /* Allow some keys to auto shift on hold */
    switch(keycode) {
        case KC_GRAVE:
            return true;
        default:
            return false;
    }
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

#ifdef AUDIO_ENABLE

#endif
