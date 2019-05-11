#include "lcd.h"
#include "characters.h"

static inline void LCDWrite(uint8_t value, uint8_t isCommand)
{
	LCD_PORT &= ~(1 << LCD_CE);
	if(isCommand)
	{
		LCD_PORT &= ~(1 << LCD_DC);
	}
	else
	{
		LCD_PORT |= (1 << LCD_DC); // It is data
	}

	SPDR = value;					//Send value to SPI register
	while (!(SPSR & (1 << SPIF)));	//Wait for byte to be sent

	LCD_PORT |= (1 << LCD_CE);
}
uint8_t LCDGetBacklight(void)
{
	return(!(PORTB & (1 << LCD_BL)));
}

void LCDSetBacklight(uint8_t state)
{
	if (state == 1)
	{
		PORTB &= ~(1 << LCD_BL); //
	}
	else
	{
		PORTB |= (1 << LCD_BL); //
	}	

}
void LCDSetContrast(uint8_t contrast)
{
	LCDWrite(0x21,1); //Extended commands
	if(contrast > 0x7F)
	{
		LCDWrite(0x80 | CONTRAST_MAX,1); //Voltage LCD = 3.06 + (0x7F & value) * 0.06 = 7.02 V 
	}
	else
	{
		LCDWrite(0x80 | contrast,1); //Voltage LCD = 3.06 + (0x7F & value) * 0.06 = 7.02 V 
	}

}
void LCDInitialize(void)
{
	uint8_t LCDContrast;
	LCD_DDR |= (1 << LCD_RST) | (1 << LCD_DC) | (1 << LCD_CE) | (1 << LCD_BL); //Output LCD control pins
	LCD_DDR |= (1 << LCD_DIN) | (1 << LCD_CLK); //Output SPI pins
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPI2X); //Enable SPI | Master | Fosc/2 = 20MHz/2=10MHz
	
	//Reset LCD
	LCD_PORT |= (1 << LCD_RST) | (1 << LCD_CE) | (1 << LCD_BL);
	// _delay_ms(10);
	LCD_PORT &= ~(1 << LCD_RST);
	_delay_ms(100);
	LCD_PORT |= (1 << LCD_RST);
	LCD_PORT &= ~(1 << LCD_CE);

	//LCDWrite(0x80,1);
	//LCDWrite(0x40,1);

	LCDContrast = eeprom_read_byte((uint8_t *)ROM_CONTRAST);
	if(LCDContrast == 0xFF)
	{
		LCDContrast = CONTRAST_DEFAULT;
		eeprom_update_byte((uint8_t *)ROM_CONTRAST,LCDContrast);
	}
	LCDSetContrast(LCDContrast);
	
	LCDWrite(0x40,1);
	LCDWrite(0x20,1); //Standard commands //Addressing ?
	LCDWrite(0x0C,1); //Normal mode

	//Cursor home
	// LCDWrite(0x80,1);
	// LCDWrite(0x40,1);
	LCDCursorHome();
	LCDClearBuffer();
	LCDcoordinateX =		0;
	LCDcoordinateY =		0;
	LCDbufferCounter =		0;
	_LCDReverseCharColor = 	0;
	LCDSetBacklight(eeprom_read_byte((uint8_t *)ROM_BACKLIGHT));
}

void LCDClearBuffer(void)
{
	int index;
	for(index = 0;index < SCREEN_BYTE_COUNT;index++)
	{
		LCDscreenBuffer[index] = 0;
	}
}

static uint8_t reverseByte(uint8_t b) {
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
	return b;
}
void LCDRender(void)
{
	int i;
	//LCDCursorHome();
	for(i = SCREEN_BYTE_COUNT-1;i >= 0;i--)
	{
		LCDWrite(reverseByte(LCDscreenBuffer[i]),0);
	}
	LCDbufferCounter=0;
}

void LCDCursorHome(void)
{
	//Cursor home
	LCDWrite(0x80,1);
	LCDWrite(0x40,1);
	LCDbufferCounter=0;
}

void LCDPrintChar(char character)
{
	uint8_t column;
	for(column = 0;column < 5;column++)
	{
		if(_LCDReverseCharColor == 0)
		{
			LCDscreenBuffer[LCDbufferCounter] = pgm_read_byte(&CHARSET[character-0x20][column]);
		}
		else
		{
			LCDscreenBuffer[LCDbufferCounter] = ~pgm_read_byte(&CHARSET[character-0x20][column]);
		}
		LCDbufferCounter++;
		LCDcoordinateX = LCDbufferCounter % 84;
		LCDcoordinateY = LCDbufferCounter / 84;
	}
}

void LCDPrintString(char string[])
{
	while(*string > 0)
	{
		if(*string == '\n')
		{
			LCDNewLine();
		}
		else
		{
			LCDPrintChar(*string);
		}
		string++;
	}
}

void LCDPrintuint16(uint16_t value)
{
	uint16_t decimalI=1;
	uint16_t valueTemp = value;
	uint8_t decimals = 0;
	if (value == 0) {
		LCDPrintChar('0');
	}
	while(valueTemp > 0)
	{
		valueTemp/=10;
		decimals++;
	}
	decimals--;
	for(uint8_t iTemp=0;iTemp<decimals;iTemp++)
	{
		decimalI*=10;
	}

	for(;decimalI >=1;decimalI/=10)
	{
		LCDPrintChar('0' + ((value/decimalI)%10));
	}
}

void LCDSetCharColorInversion(uint8_t reversed)
{
	if(reversed)
	{
		_LCDReverseCharColor = 1;
	}
	else
	{
		_LCDReverseCharColor = 0;
	}
}
void LCDFillLine(void)
{
	int i = 0;
	int end = (84-(LCDbufferCounter%84));
	for(;i<end;i++)
	{
		if(_LCDReverseCharColor == 0)
		{
			LCDscreenBuffer[LCDbufferCounter] = 0x00;
		}
		else
		{
			LCDscreenBuffer[LCDbufferCounter] = ~0x00;
		}
		LCDbufferCounter++;
	}


}

void LCDNewLine(void)
{	
		LCDbufferCounter+=(84-(LCDbufferCounter%84));
		LCDcoordinateX = LCDbufferCounter % 84;
		LCDcoordinateY = LCDbufferCounter / 84;
}

// changed uint to int, to fix undefined behaviour
void LCDSetPixel(int8_t x, int8_t y) {
	if (y < 0) y = 48 + y;
	if (x < 0) x = 84 + x;
	LCDscreenBuffer[x % 84 + (y % 48)/8 * 84] = LCDscreenBuffer[x % 84 + (y % 48)/8 * 84] |= (1 << (y%8));
}


// Places Sprite at x, y at anchor of left upper corner of sprite.
void LCDPlaceSprite(uint8_t x, uint8_t y, uint8_t rotation, Sprite sprite) {
	uint8_t leftoverBits = 8 * sprite.sizeBytes - sprite.sizey;
	for (uint8_t row = 0; row < sprite.sizex; row++) {
		for (uint8_t col = 0; col < sprite.sizeBytes; col++) {
			uint8_t bankCoord = 8 * (sprite.sizeBytes - col - 1) - leftoverBits;
			uint8_t byte = pgm_read_byte(sprite.data + (row * sprite.sizeBytes) + col);
			int8_t currentBit = 8;
			uint8_t usableBits = 8;
			if (leftoverBits && col == sprite.sizeBytes - 1) {
				currentBit = leftoverBits;
				bankCoord = -leftoverBits;
			}
			if (byte) {
				switch (rotation)
					{
						//Default loaded from images.h
						case 0:
							for (; currentBit >= 0; currentBit--) {
								if (byte & (1 << (usableBits - currentBit))) {
									LCDSetPixel(x + row, y + (usableBits - currentBit) + bankCoord);
								}
							}
							break;
						//Rotate default 180 deg
						case 1:
							for (; currentBit >= 0; currentBit--) {
								if (byte & (1 << (usableBits - currentBit))) {
									LCDSetPixel(x + sprite.sizex - row - 1, y + (sprite.sizey) - (usableBits - currentBit) - bankCoord - 1);
								}
							}
							break;
						//90 deg Counterclockwise
						case 2:
							for (; currentBit >= 0; currentBit--) {
								if (byte & (1 << (usableBits - currentBit))) {
									LCDSetPixel(x + (usableBits - currentBit) + bankCoord, y + sprite.sizey - row - 1);
								}
							}
							break;
						//90 deg Clockwise
						case 3:
							for (; currentBit >= 0; currentBit--) {
								if (byte & (1 << (usableBits - currentBit))) {
									LCDSetPixel(x + sprite.sizex - (usableBits - currentBit) - bankCoord - 1, y + row);
								}
							}
							break;
						//Mirror normal
						case 4:
							for (; currentBit >= 0; currentBit--) {
								if (byte & (1 << (usableBits - currentBit))) {
									LCDSetPixel(x + sprite.sizex - row - 1, y + (usableBits - currentBit) + bankCoord);
								}
							}
							break;
						//Mirror 180 degs rotated normal
						case 5:
							for (; currentBit >= 0; currentBit--) {
								if (byte & (1 << (usableBits - currentBit))) {
									LCDSetPixel(x + row, y + (sprite.sizey) - (usableBits - currentBit) - bankCoord - 1);
								}
							}
							break;
						//Mirror 90 deg
						case 6:
							for (; currentBit >= 0; currentBit--) {
								if (byte & (1 << (usableBits - currentBit))) {
									LCDSetPixel(x + (usableBits - currentBit) + bankCoord, y + row - 1);
								}
							}
							break;
					}
			}
		}
	}
}
