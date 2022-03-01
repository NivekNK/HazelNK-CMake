#pragma once

// From glfw3.h
#define NK_KEY_SPACE              32
#define NK_KEY_APOSTROPHE         39  /* ' */
#define NK_KEY_COMMA              44  /* , */
#define NK_KEY_MINUS              45  /* - */
#define NK_KEY_PERIOD             46  /* . */
#define NK_KEY_SLASH              47  /* / */
#define NK_KEY_0                  48
#define NK_KEY_1                  49
#define NK_KEY_2                  50
#define NK_KEY_3                  51
#define NK_KEY_4                  52
#define NK_KEY_5                  53
#define NK_KEY_6                  54
#define NK_KEY_7                  55
#define NK_KEY_8                  56
#define NK_KEY_9                  57
#define NK_KEY_SEMICOLON          59  /* ; */
#define NK_KEY_EQUAL              61  /* = */
#define NK_KEY_A                  65
#define NK_KEY_B                  66
#define NK_KEY_C                  67
#define NK_KEY_D                  68
#define NK_KEY_E                  69
#define NK_KEY_F                  70
#define NK_KEY_G                  71
#define NK_KEY_H                  72
#define NK_KEY_I                  73
#define NK_KEY_J                  74
#define NK_KEY_K                  75
#define NK_KEY_L                  76
#define NK_KEY_M                  77
#define NK_KEY_N                  78
#define NK_KEY_O                  79
#define NK_KEY_P                  80
#define NK_KEY_Q                  81
#define NK_KEY_R                  82
#define NK_KEY_S                  83
#define NK_KEY_T                  84
#define NK_KEY_U                  85
#define NK_KEY_V                  86
#define NK_KEY_W                  87
#define NK_KEY_X                  88
#define NK_KEY_Y                  89
#define NK_KEY_Z                  90
#define NK_KEY_LEFT_BRACKET       91  /* [ */
#define NK_KEY_BACKSLASH          92  /* \ */
#define NK_KEY_RIGHT_BRACKET      93  /* ] */
#define NK_KEY_GRAVE_ACCENT       96  /* ` */
#define NK_KEY_WORLD_1            161 /* non-US #1 */
#define NK_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define NK_KEY_ESCAPE             256
#define NK_KEY_ENTER              257
#define NK_KEY_TAB                258
#define NK_KEY_BACKSPACE          259
#define NK_KEY_INSERT             260
#define NK_KEY_DELETE             261
#define NK_KEY_RIGHT              262
#define NK_KEY_LEFT               263
#define NK_KEY_DOWN               264
#define NK_KEY_UP                 265
#define NK_KEY_PAGE_UP            266
#define NK_KEY_PAGE_DOWN          267
#define NK_KEY_HOME               268
#define NK_KEY_END                269
#define NK_KEY_CAPS_LOCK          280
#define NK_KEY_SCROLL_LOCK        281
#define NK_KEY_NUM_LOCK           282
#define NK_KEY_PRINT_SCREEN       283
#define NK_KEY_PAUSE              284
#define NK_KEY_F1                 290
#define NK_KEY_F2                 291
#define NK_KEY_F3                 292
#define NK_KEY_F4                 293
#define NK_KEY_F5                 294
#define NK_KEY_F6                 295
#define NK_KEY_F7                 296
#define NK_KEY_F8                 297
#define NK_KEY_F9                 298
#define NK_KEY_F10                299
#define NK_KEY_F11                300
#define NK_KEY_F12                301
#define NK_KEY_F13                302
#define NK_KEY_F14                303
#define NK_KEY_F15                304
#define NK_KEY_F16                305
#define NK_KEY_F17                306
#define NK_KEY_F18                307
#define NK_KEY_F19                308
#define NK_KEY_F20                309
#define NK_KEY_F21                310
#define NK_KEY_F22                311
#define NK_KEY_F23                312
#define NK_KEY_F24                313
#define NK_KEY_F25                314
#define NK_KEY_KP_0               320
#define NK_KEY_KP_1               321
#define NK_KEY_KP_2               322
#define NK_KEY_KP_3               323
#define NK_KEY_KP_4               324
#define NK_KEY_KP_5               325
#define NK_KEY_KP_6               326
#define NK_KEY_KP_7               327
#define NK_KEY_KP_8               328
#define NK_KEY_KP_9               329
#define NK_KEY_KP_DECIMAL         330
#define NK_KEY_KP_DIVIDE          331
#define NK_KEY_KP_MULTIPLY        332
#define NK_KEY_KP_SUBTRACT        333
#define NK_KEY_KP_ADD             334
#define NK_KEY_KP_ENTER           335
#define NK_KEY_KP_EQUAL           336
#define NK_KEY_LEFT_SHIFT         340
#define NK_KEY_LEFT_CONTROL       341
#define NK_KEY_LEFT_ALT           342
#define NK_KEY_LEFT_SUPER         343
#define NK_KEY_RIGHT_SHIFT        344
#define NK_KEY_RIGHT_CONTROL      345
#define NK_KEY_RIGHT_ALT          346
#define NK_KEY_RIGHT_SUPER        347
#define NK_KEY_MENU               348

/*! @brief If this bit is set one or more Shift keys were held down.
 *
 *  If this bit is set one or more Shift keys were held down.
 */
#define NK_MOD_SHIFT           0x0001
 /*! @brief If this bit is set one or more Control keys were held down.
  *
  *  If this bit is set one or more Control keys were held down.
  */
#define NK_MOD_CONTROL         0x0002
  /*! @brief If this bit is set one or more Alt keys were held down.
   *
   *  If this bit is set one or more Alt keys were held down.
   */
#define NK_MOD_ALT             0x0004
   /*! @brief If this bit is set one or more Super keys were held down.
	*
	*  If this bit is set one or more Super keys were held down.
	*/
#define NK_MOD_SUPER           0x0008
	/*! @brief If this bit is set the Caps Lock key is enabled.
	 *
	 *  If this bit is set the Caps Lock key is enabled and the @ref
	 *  NK_LOCK_KEY_MODS input mode is set.
	 */
#define NK_MOD_CAPS_LOCK       0x0010
	 /*! @brief If this bit is set the Num Lock key is enabled.
	  *
	  *  If this bit is set the Num Lock key is enabled and the @ref
	  *  NK_LOCK_KEY_MODS input mode is set.
	  */
#define NK_MOD_NUM_LOCK        0x0020
