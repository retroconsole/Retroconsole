#include "menu.h"

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
				char buffer[9];
				strcpy_P(buffer, doneby);
				LCDPrintString(buffer);
				LCDNewLine();
				strcpy_P(buffer, sall);
				LCDPrintString(buffer);
				LCDNewLine();
				strcpy_P(buffer, siimer);
				LCDPrintString(buffer);
				LCDNewLine();
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