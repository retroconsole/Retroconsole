#include "menu.h"
#include "lcd.h"

static const char mainHeader[] PROGMEM = "  RetroConsole";
static const char game_1[] PROGMEM = "Pattern";
static const char game_2[] PROGMEM = "Snake";
static const char game_3[] PROGMEM = "Tetris";
static const char settings[] PROGMEM = "Settings";
static const char about[] PROGMEM = "About";

static const char settingsHeader[] PROGMEM = "    Settings";
static const char setting1[] PROGMEM = "Contrast";
static const char setting2[] PROGMEM = "Backlight";

static const char doneby[] PROGMEM = "Done by:";
static const char sall[] PROGMEM = "M.Sall";
static const char siimer[] PROGMEM = "K.Siimer";
static const char repoText[] PROGMEM = "Repository:";

static const uint8_t repo[][4] PROGMEM= {
{0b11111110, 0b00101100, 0b10111111, 0b10000000},
{0b10000010, 0b10100111, 0b10100000, 0b10000000},
{0b10111010, 0b00001010, 0b00101110, 0b10000000},
{0b10111010, 0b11101111, 0b00101110, 0b10000000},
{0b10111010, 0b01000100, 0b10101110, 0b10000000},
{0b10000010, 0b11011111, 0b10100000, 0b10000000},
{0b11111110, 0b10101010, 0b10111111, 0b10000000},
{0b00000000, 0b01110000, 0b10000000, 0b00000000},
{0b11111011, 0b11010110, 0b01010101, 0b00000000},
{0b00000100, 0b00101010, 0b10010001, 0b00000000},
{0b10000111, 0b10100101, 0b01011101, 0b10000000},
{0b10111001, 0b10001010, 0b01111001, 0b10000000},
{0b11110110, 0b11101111, 0b10101110, 0b00000000},
{0b11101100, 0b11000100, 0b10010110, 0b00000000},
{0b10001010, 0b01011111, 0b01011101, 0b10000000},
{0b10000001, 0b10110011, 0b11000001, 0b00000000},
{0b10001111, 0b11010111, 0b11111011, 0b10000000},
{0b00000000, 0b11101100, 0b10001000, 0b00000000},
{0b11111110, 0b10100010, 0b10101001, 0b10000000},
{0b10000010, 0b01101000, 0b10001001, 0b00000000},
{0b10111010, 0b10001111, 0b11111111, 0b10000000},
{0b10111010, 0b11000000, 0b01101101, 0b10000000},
{0b10111010, 0b10111010, 0b01010110, 0b10000000},
{0b10000010, 0b11010011, 0b10101100, 0b10000000},
{0b11111110, 0b11011000, 0b00011111, 0b10000000}
};

Sprite repoSprite = {25, 25, 4, *repo};


char buffer[15];
PGM_P const menuList[] PROGMEM = 
{
	mainHeader,
	game_1,
	game_2,
	game_3,
	settings,
	about
};

PGM_P const settingsList[] PROGMEM = 
{
	settingsHeader,
	setting1,
	setting2
};

void MENUMain(void)
{
	printRow = 0;
	selection = HEADER_ROWS;
	while(1)
	{
		for(printRow=0;printRow < MENU_ROWS;printRow++)
		{

			strcpy_P(buffer,(PGM_P)pgm_read_word(&(menuList[printRow])));
			if(selection == printRow)
			{
				LCDSetCharColorInversion(1);
				LCDPrintString(buffer);
				LCDFillLine();
				LCDSetCharColorInversion(0);
			}
			else
			{
				LCDPrintString(buffer);
				LCDNewLine();
			}
		}
		LCDRender();
		LCDClearBuffer();
		if((BUTTONGet(UP)) && (selection > HEADER_ROWS))
		{
			selection--;
		}
		else if((BUTTONGet(DOWN)) && (selection < (MENU_ROWS-1)))
		{
			selection++;
		}
		else if(BUTTONGet(RIGHT))
		{
			if(selection == MENU_SELECTION_PATTERN)
			{
				PATTERNMain();
			}
			if(selection == MENU_SELECTION_SNAKE)
			{
				SNAKEMain();
			}
			else if(selection == MENU_SELECTION_TETRIS)
			{
				TETRISMain();
			}
			else if(selection == MENU_SELECTION_ABOUT)
			{
				while(1) {
				char buffer[20];
				strcpy_P(buffer, doneby);
				LCDPrintString(buffer);
				LCDNewLine();
				strcpy_P(buffer, sall);
				LCDPrintString(buffer);
				LCDNewLine();
				strcpy_P(buffer, siimer);
				LCDPrintString(buffer);
				LCDNewLine();
				LCDNewLine();
				strcpy_P(buffer, repoText);
				LCDPrintString(buffer);
				LCDNewLine();
				LCDPlaceSprite(83-25,47-25,0, repoSprite);
				LCDRender();
				_delay_ms(100);
				if (BUTTONGet(LEFT)) {
					LCDClearBuffer();
					break;
					}
				}
			}
			else if(selection == MENU_SELECTION_SETTINGS)
			{
				_delay_ms(500);
				MENUSettings();
			}
		}

		_delay_ms(150);
	}
	
}

void MENUSettings(void)
{
	uint8_t lcdContrast;
	printRow=0;
	selection = HEADER_ROWS;
	while(1)
	{
		LCDClearBuffer();
		for(printRow=0;printRow < SETTING_ROWS;printRow++)
		{

			strcpy_P(buffer,(PGM_P)pgm_read_word(&(settingsList[printRow])));
			if(selection == printRow)
			{
				LCDSetCharColorInversion(1);
				LCDPrintString(buffer);
				LCDFillLine();
				LCDSetCharColorInversion(0);
			}
			else
			{
				LCDPrintString(buffer);
				LCDNewLine();
			}
		}
		LCDRender();
		if((BUTTONGet(UP)) && (selection > HEADER_ROWS))
		{
			selection--;
		}
		else if((BUTTONGet(DOWN)) && (selection < (SETTING_ROWS-1)))
		{
			selection++;
		}
		else if(BUTTONGet(RIGHT))
		{
			if(selection == SETTINGS_SELECTION_BACKLIGHT)
			{
				while(1)
				{
					LCDbufferCounter = LCD_SCREEN_COLUMNS * SETTINGS_SELECTION_BACKLIGHT;
					strcpy_P(buffer,(PGM_P)pgm_read_word(&(settingsList[SETTINGS_SELECTION_BACKLIGHT])));
					LCDSetCharColorInversion(1);
					LCDPrintString(buffer);
					LCDPrintChar(' ');
					LCDPrintChar(' ');
					LCDbufferCounter-=LCD_CHAR_WIDTH;

					LCDPrintChar('0'+LCDGetBacklight());
					LCDFillLine();
					LCDRender();
					LCDSetCharColorInversion(0);
					// LCDbufferCounter--;
					// LCDbufferCounter-=LCDbufferCounter%LCD_SCREEN_COLUMNS;

					if(BUTTONGet(UP))
					{
						LCDSetBacklight(1);
					}
					else if(BUTTONGet(DOWN))
					{
						LCDSetBacklight(0);
					}
					else if(BUTTONGet(LEFT))
					{
						if(LCDGetBacklight() != eeprom_read_byte((uint8_t *)ROM_BACKLIGHT))
						{
							eeprom_update_byte((uint8_t *)ROM_BACKLIGHT, LCDGetBacklight());
						}

						_delay_ms(300);
						break;
					}

				}
			}
			else if(selection == SETTINGS_SELECTION_CONTRAST)
			{
				_delay_ms(100);
				lcdContrast=eeprom_read_byte((uint8_t *)ROM_CONTRAST);
				while(1)
				{
					LCDbufferCounter = LCD_SCREEN_COLUMNS * SETTINGS_SELECTION_CONTRAST;
					strcpy_P(buffer,(PGM_P)pgm_read_word(&(settingsList[SETTINGS_SELECTION_CONTRAST])));
					LCDSetCharColorInversion(1);
					LCDPrintString(buffer);
					LCDPrintChar(' ');

					LCDPrintChar(' ');
					LCDPrintChar(' ');
					LCDPrintChar(' ');
					LCDbufferCounter-=LCD_CHAR_WIDTH*3;

					LCDPrintChar('0'+lcdContrast/100);
					LCDPrintChar('0'+((lcdContrast/10)%10));
					LCDPrintChar('0'+(lcdContrast%10));

					LCDFillLine();
					LCDRender();
					LCDSetCharColorInversion(0);

					if(BUTTONGet(UP))
					{
						if(lcdContrast < CONTRAST_MAX)
						{
							lcdContrast++;
						}
						while(BUTTONGet(UP));
					}
					else if(BUTTONGet(DOWN))
					{
						if(lcdContrast > CONTRAST_MIN)
						{
							lcdContrast--;
						}
						while(BUTTONGet(DOWN));
					}
					else if(BUTTONGet(LEFT))
					{
						if(lcdContrast != eeprom_read_byte((uint8_t *)ROM_CONTRAST))
						{
							eeprom_update_byte((uint8_t *)ROM_CONTRAST, lcdContrast);
						}

						_delay_ms(300);
						break;
					}
				}
			}
		}
		else if(BUTTONGet(LEFT))
		{
			LEDSet(LED1,0);
			selection=HEADER_ROWS;
			break;
		}
		_delay_ms(150);
	}
	
}