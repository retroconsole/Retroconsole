#include "avr/io.h"
#include <avr/eeprom.h>
#include "romaddresses.h"

#include <avr/pgmspace.h>
#include <util/delay.h>

#include "lcd.h"
#include "buttons.h"
#include "led.h"
#include "tetris.h"
#include "snake.h"
#include "pattern.h"

#include "random.h"
#include "millis.h"

#define HEADER_ROWS 1

#define MENU_ROWS 6
#define MENU_SELECTION_PATTERN		1
#define MENU_SELECTION_SNAKE 		2
#define MENU_SELECTION_TETRIS 		3
#define MENU_SELECTION_SETTINGS 	4
#define MENU_SELECTION_ABOUT	 	5

#define SETTING_ROWS 3
#define SETTINGS_SELECTION_CONTRAST 	1
#define SETTINGS_SELECTION_BACKLIGHT 	2

uint8_t selection, printRow;
void MENUMain(void);
void MENUSettings(void);
