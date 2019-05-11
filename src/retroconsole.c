#include <avr/io.h>
#include <avr/eeprom.h>
#include "romaddresses.h"

#include <util/delay.h>
#include "lcd.h"
//#include "images.h"
#include "buttons.h"
#include "menu.h"
#include "led.h"
#include "millis.h"

#define BLINK_DELAY 1000

int main(void)
{
	BUTTONSInitialize();
	// LEDInitialize(); //Not required when LED-s are not installed
	LCDInitialize();
	MILLISInit();
	MENUMain();
	return 0;
}