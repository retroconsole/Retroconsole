#include "pattern.h"

static const char stringGameOver[] PROGMEM = "   Game Over!\n   Score:  ";
PGM_P const PATTERNStrings[] PROGMEM = 
{
	stringGameOver
};
static char buffer[30];

static const uint8_t PATTERNEmpty[][1] PROGMEM =	
{
	{0xff},{0xff},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0x80},{0x01},
	{0xff},{0xff}
};

static const uint8_t PATTERNFilled[][1] PROGMEM =	
{
	{0xff},{0xff},
	{0x80},{0x01},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0xbf},{0xfd},
	{0x80},{0x01},
	{0xff},{0xff}
};

Sprite patternEmpty = 
{
	PATTERN_EDGE_LEN, 
	PATTERN_EDGE_LEN,
	2, 
	*PATTERNEmpty
};
Sprite patternFilled = 
{
	PATTERN_EDGE_LEN, 
	PATTERN_EDGE_LEN,
	2, 
	*PATTERNFilled
};
void PATTERNInit()
{
	PATTERNScore=0;
	PATTERNSeed=MILLISGet();
}

void PATTERNPrintScore()
{
	LCDbufferCounter=4*LCD_SCREEN_COLUMNS+1;
	LCDPrintString("Score");
	LCDbufferCounter=5*LCD_SCREEN_COLUMNS+1;
	LCDPrintuint16(PATTERNScore);

}
void PATTERNMain()
{
	uint8_t gameRunning = 1;
	uint16_t stepIndex;
	PATTERNInit();
	
	while(gameRunning)
	{
		//Show pattern
		RANDOMSeed(PATTERNSeed);
		for(stepIndex=0;stepIndex<PATTERNScore + 1;stepIndex++)
		{
			PATTERNRender(RANDOMGet()%4);
			if (BUTTONGet(BUTTON2)) break;
		}

		//Check user moves
		RANDOMSeed(PATTERNSeed);
		for(stepIndex=0;stepIndex<PATTERNScore + 1;stepIndex++)
		{
			boxValue=RANDOMGet()%4;
			while((PIND & 0x3C) == 0x3C)
			{
				_delay_ms(1);
			}
			if(BUTTONGet(LEFT+boxValue))
			{
				PATTERNRender(boxValue);
			}
			else
			{
				gameRunning=0; //Game over
			}

			if (BUTTONGet(BUTTON2)) break;
		}
		if(gameRunning)
		{
			PATTERNScore++;
		}
		// _delay_ms(300);
		while((PIND & 0x3C) != 0x3C)
		{
			_delay_ms(1);
		}


		if (BUTTONGet(BUTTON2)) break;
	}

	// LCDbufferCounter=0;
	strcpy_P(buffer,(PGM_P)pgm_read_word(&(PATTERNStrings[0])));
	LCDPrintString(buffer);
	LCDPrintuint16(PATTERNScore);
	LCDRender();
	_delay_ms(3000);

}

void PATTERNRender(uint8_t selectedBlock)
{
	uint8_t i,k;
	uint8_t x,y;
	for(k=0;k<2;k++)
	{
		for(i=0;i<4;i++)
		{
			x=(LCD_SCREEN_COLUMNS/2)-(PATTERN_EDGE_LEN/2);
			y=PATTERN_EDGE_LEN;
			if(i==0)
			{
				x-=PATTERN_EDGE_LEN;
			}
			else if (i==1)
			{
				y=0;
			}
			else if (i==2)
			{
				y=PATTERN_EDGE_LEN*2;
			}
			else if(i==3)
			{
				x+=PATTERN_EDGE_LEN;
			}
			
			if((k == 0)&&(i==selectedBlock))
			{
				LCDPlaceSprite(x, y, 2, patternFilled);
			}
			else
			{
				LCDPlaceSprite(x, y, 2, patternEmpty);
			}
		}
		PATTERNPrintScore();
		LCDRender();
		LCDClearBuffer();
		_delay_ms(400);
	}
}

