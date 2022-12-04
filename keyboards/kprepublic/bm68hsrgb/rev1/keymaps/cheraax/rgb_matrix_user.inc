// !!! DO NOT ADD #pragma once !!! //
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(game_breathing)
RGB_MATRIX_EFFECT(game_led_effect_key_only)
RGB_MATRIX_EFFECT(game_led_effect)
RGB_MATRIX_EFFECT(cool_keys)
RGB_MATRIX_EFFECT(blind_type_key_only)
RGB_MATRIX_EFFECT(blind_type)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
int HUE_STEP = 40;
int SPEED_STEP = 127;
int MV_FLAG = 1, CM_FLAG = 2, EXT_FLAG = 3, ADD_FLAG = 4, ADD_FLAG2 = 5, BG_FLAG = 0;
RGB mv_key, cm_key, ext_key, ad_key, ad_key2, bg_key ;
HSV hsv;
int GAME_LED_CONFIG[] = {
    // LED Index to Flag
    2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, =, Backspace, Delete
    2, 5, 1, 5, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0,  // Tab, Q, W, E, R, T, Y, U, I, O, P, [, ], backslash , Home
    0, 1, 1, 1, 0, 4, 0, 0, 0, 0, 0, 0,    0, 0,  // Capslock, A, S, D, F, G, H, J, K, L, ;, ', Enter, Page up
       5, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0,  // LShift, Z, X, C, V, B, N, M, ,, ., /, Shift, Up, Page Down
    5, 0, 0,          2,       0, 0, 0, 2, 2, 2,  // Ctrl, GUI, Alt, Space, RAlt, FN, Ctrl, Left, Down, Right
    9, 9, 9, 9, 9, 9  // UNDERGLOW
};
int COOL_LED_CONFIG[] = {
    // LED Index to Flag
    3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0,  // Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, =, Backspace, Delete
    4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,  // Tab, Q, W, E, R, T, Y, U, I, O, P, [, ], backslash , Home
    4, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0,    2, 4,  // Capslock, A, S, D, F, G, H, J, K, L, ;, ', Enter, Page up
       2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 3,  // LShift, Z, X, C, V, B, N, M, ,, ., /, Shift, Up, Page Down
    2, 3, 2,          0,       5, 5, 5, 4, 4, 4,  // Ctrl, GUI, Alt, Space, RAlt, FN, Ctrl, Left, Down, Right
    9, 9, 9, 9, 9, 9  // UNDERGLOW
};
int BLIND_TYPING_CONFIG[] = {
    // LED Index to Flag
    0, 1, 2, 3, 4, 4, 5, 5, 3, 2, 1, 1, 1, 0, 0,  // Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, =, Backspace, Delete
    0, 1, 2, 3, 4, 4, 5, 5, 3, 2, 1, 1, 1, 0, 0,  // Tab, Q, W, E, R, T, Y, U, I, O, P, [, ], backslash , Home
    0, 1, 2, 3, 4, 4, 5, 5, 3, 2, 1, 1,    0, 0,  // Capslock, A, S, D, F, G, H, J, K, L, ;, ', Enter, Page up
       0, 1, 2, 3, 4, 4, 5, 5, 3, 2, 1, 0, 0, 0,  // LShift, Z, X, C, V, B, N, M, ,, ., /, Shift, Up, Page Down
    0, 0, 0,          0,       5, 5, 5, 0, 0, 0,  // Ctrl, GUI, Alt, Space, RAlt, FN, Ctrl, Left, Down, Right
    9, 9, 9, 9, 9, 9  // UNDERGLOW
};

static bool equal(int field, int flag){
  if (field == flag){
    return true;
  }
  return false;
}
static bool set_rgb_effect(int mode, int LED_CONFIG[], effect_params_t* params){
  // mode:
  // 1 - breathing
  // 2 - game with backlight
  // 3 - game without backlight
  // 0 - other
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_config.speed = SPEED_STEP;
  hsv  = rgb_matrix_config.hsv;
  if (mode == 1){
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 16);
    hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
  }
  hsv.h += HUE_STEP;
  mv_key = rgb_matrix_hsv_to_rgb(hsv);
  hsv.h += HUE_STEP;
  cm_key = rgb_matrix_hsv_to_rgb(hsv);
  hsv.h += HUE_STEP;
  ext_key = rgb_matrix_hsv_to_rgb(hsv);
  hsv.h += HUE_STEP;
  ad_key = rgb_matrix_hsv_to_rgb(hsv);
  hsv.h += HUE_STEP;
  ad_key2 = rgb_matrix_hsv_to_rgb(hsv);

  for (int i = 0; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();
    if (equal(LED_CONFIG[i], MV_FLAG)) { //LED_FLAG_MODIFIER
        rgb_matrix_set_color(i, mv_key.r, mv_key.g, mv_key.b);
    } else if (equal(LED_CONFIG[i], CM_FLAG)){
        rgb_matrix_set_color(i, cm_key.r, cm_key.g, cm_key.b);
    } else if (equal(LED_CONFIG[i], EXT_FLAG)){
        rgb_matrix_set_color(i, ext_key.r, ext_key.g, ext_key.b);
    } else if (equal(LED_CONFIG[i], ADD_FLAG)){
        rgb_matrix_set_color(i, ad_key.r, ad_key.g, ad_key.b);
    } else if (equal(LED_CONFIG[i], ADD_FLAG2)){
        rgb_matrix_set_color(i, ad_key2.r, ad_key2.g, ad_key2.b);
    } else if (equal(LED_CONFIG[i], BG_FLAG)){
      if (mode == 2){
        float bright_lvl = 0.6;
        HSV bg_hsv = { (int)(bright_lvl*rgb_matrix_config.hsv.h), (int)(bright_lvl*rgb_matrix_config.hsv.s), (int)(bright_lvl*rgb_matrix_config.hsv.v)}; 
        bg_key = rgb_matrix_hsv_to_rgb(bg_hsv);
        rgb_matrix_set_color(i, bg_key.r, bg_key.g, bg_key.b);
      }else if (mode == 1 || mode == 3){
        rgb_matrix_set_color(i, BG_FLAG, BG_FLAG, BG_FLAG);
      }else{
        bg_key = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
        rgb_matrix_set_color(i, bg_key.r, bg_key.g, bg_key.b);
      }
    }
    }
  return rgb_matrix_check_finished_leds(led_max);
}
static bool game_led_effect(effect_params_t* params) {
  return set_rgb_effect(2, GAME_LED_CONFIG, params);
}
static bool game_led_effect_key_only(effect_params_t* params) {
  return set_rgb_effect(3, GAME_LED_CONFIG, params);
}
bool game_breathing(effect_params_t* params) {
  return set_rgb_effect(1, GAME_LED_CONFIG, params);
}
static bool cool_keys(effect_params_t* params) {
  return set_rgb_effect(0, COOL_LED_CONFIG, params);
}
static bool blind_type(effect_params_t* params) {
  return set_rgb_effect(0, BLIND_TYPING_CONFIG, params);
}
static bool blind_type_key_only(effect_params_t* params) {
  return set_rgb_effect(3, BLIND_TYPING_CONFIG, params);
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS