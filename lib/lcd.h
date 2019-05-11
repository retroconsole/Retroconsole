#ifndef LCD_H
#define LCD_H
#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "romaddresses.h"
#define LCD_DDR		DDRB
#define LCD_PORT	PORTB

#define LCD_RST		PB1	// Reset
#define LCD_CE		PB2	// Chip enable
#define LCD_DIN		PB3
#define LCD_DC		PB4	// Data/!Command pin
#define LCD_CLK		PB5

#define LCD_BL PB0

#define CONTRAST_DEFAULT 75
#define CONTRAST_MIN 65

#define CONTRAST_MAX 85
// #define CONTRAST 85
// #define CONTRAST 65
#define LCD_SCREEN_COLUMNS 84
#define LCD_SCREEN_LINES 6
#define SCREEN_BYTE_COUNT 504 // (84*6)

#define LCD_CHAR_WIDTH 5

uint8_t LCDscreenBuffer[SCREEN_BYTE_COUNT];
uint8_t LCDcoordinateX;
uint8_t LCDcoordinateY;
uint16_t LCDbufferCounter;
uint8_t _LCDReverseCharColor;
void LCDSetBacklight(uint8_t state);
uint8_t LCDGetBacklight(void);
void LCDInitialize(void);
// static inline void LCDWrite(uint8_t data, uint8_t dataBoolean);
void LCDClearBuffer(void);
void LCDRender(void);
void LCDCursorHome(void);
void LCDPrintChar(char character);
void LCDSetCharColorInversion(uint8_t reversed);
void LCDFillLine(void);
void LCDPrintString(char *string);
void LCDPrintuint16(uint16_t value);
void LCDNewLine(void);

//Sprite struct
typedef struct sprite {
	uint8_t sizex;
	uint8_t sizey;
	uint8_t sizeBytes;
	const uint8_t *data;
} Sprite;

//LCD Buffer control functions
uint8_t LCDByteSizeCalc(uint8_t spriteCols);
void LCDPlaceSprite(uint8_t x, uint8_t y, uint8_t rotation, Sprite sprite);
void LCDSetPixel(int8_t x, int8_t y);

#endif /*LCD_H*/