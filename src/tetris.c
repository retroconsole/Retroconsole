#include "tetris.h"
uint8_t TETRISGameField[TETRIS_ROWS][TETRIS_COLUMNS] = {0};

static const uint8_t TETRISEmpty[][1] PROGMEM = {{0x00},{0x00},{0x00}};
static const uint8_t TETRISBlock[][1] PROGMEM = {{0xe0},{0xe0},{0xe0}};
static const uint8_t TETRISDot[][1] PROGMEM = 	{{0xe0},{0xa0},{0xe0}};

static const char stringGameOver[] PROGMEM = "   Game Over!\n   Score:  ";
PGM_P const TETRISStrings[] PROGMEM = 
{
	stringGameOver
};
static char buffer[30];
Sprite tetrisEmpty = 
{
	TETRIS_BLOCK_LENGTH, 
	TETRIS_BLOCK_LENGTH,
	1, 
	*TETRISEmpty
};

Sprite tetrisBlock = 
{
	TETRIS_BLOCK_LENGTH, 
	TETRIS_BLOCK_LENGTH,
	1,
	*TETRISBlock
};

Sprite tetrisDot = 
{
	TETRIS_BLOCK_LENGTH, 
	TETRIS_BLOCK_LENGTH,
	1, 
	*TETRISDot
};

static const uint8_t tetriminos[TETRIS_TETRIMINOS] PROGMEM = 
{
	0b01001110, /*TETRIMINO_T*/
	0b11001100, /*TETRIMINO_SQUARE*/
	0b11110000, /*TETRIMINO_LONG*/
	0b10001110, /*TETRIMINO_L_RIGHT*/
	0b00101110, /*TETRIMINO_L_LEFT*/
	0b11000110, /*TETRIMINO_DOG_LEFT*/
	0b01101100  /*TETRIMINO_DOG_RIGHT*/
	
};

Tetrimino currentTetrimino = {0};

void TETRISInit(void)
{
	uint8_t row;
	uint8_t column;
	for(row=0;row<TETRIS_ROWS;row++)
	{
		for(column=0;column<TETRIS_COLUMNS;column++)
		{
			TETRISGameField[row][column] = 0;
		}
	}

	for(row=0;row<TETRIS_ROWS;row++)
	{
		TETRISGameField[row][0] = TETRIS_EDGE;
		TETRISGameField[row][TETRIS_COLUMNS-1] = TETRIS_EDGE;
	}
	for(column=0;column<TETRIS_COLUMNS;column++)
	{
		TETRISGameField[TETRIS_ROWS-1][column] = TETRIS_EDGE;
	}
}

void TETRISRender(void)
{
	uint8_t row,column;
	for(row=0;row<TETRIS_ROWS;row++)
	{
		for(column = 0;column<TETRIS_COLUMNS;column++)
		{
			if(TETRISGameField[row][column])
			{
				LCDPlaceSprite(
					TETRIS_LEFT_EDGE+column*TETRIS_BLOCK_LENGTH,
					row*TETRIS_BLOCK_LENGTH,
					0,
					tetrisBlock);
			}
			else
			{
				LCDPlaceSprite(
					TETRIS_LEFT_EDGE+column*TETRIS_BLOCK_LENGTH,
					row*TETRIS_BLOCK_LENGTH,
					0,
					tetrisEmpty);
			}
			
		}
	}

	LCDbufferCounter=2*LCD_SCREEN_COLUMNS+TETRIS_RIGHT_EDGE-1;
	LCDPrintString("Score");
	LCDbufferCounter=3*LCD_SCREEN_COLUMNS+TETRIS_RIGHT_EDGE-1;
	LCDPrintuint16(TETRISScore);

	LCDRender();
	LCDClearBuffer();
}

void TETRISMoveBlock(int8_t direction)
{
	int8_t row,column,edge;
	edge = 0;
	for(row=(TETRIS_ROWS-2);row>=0;--row)
	{
		for(column=1;(column<(TETRIS_COLUMNS-1)) && (edge == 0);column++)
		{
			if(direction==-1)
			{
				if((TETRISGameField[row][column]==TETRIS_BLOCK_MOVING) && ((column==1) || ((TETRISGameField[row][column-1])==TETRIS_BLOCK)))
				{
					edge=1;
				}
			}
			else if(direction == 1)
			{
				if((TETRISGameField[row][column]==TETRIS_BLOCK_MOVING) && ((column==(TETRIS_COLUMNS-2)) || ((TETRISGameField[row][column+1])==TETRIS_BLOCK)))
				{
					edge=1;
				}
			}
		}
	}
	if(!edge)
	{
		currentTetrimino.x += direction;
		for(row=(TETRIS_ROWS-2);row>=0;--row)
		{
			if(direction==-1)
			{
				for(column=1;column<(TETRIS_COLUMNS-1);column++)
				{
					if(TETRISGameField[row][column]==TETRIS_BLOCK_MOVING)
					{
						TETRISGameField[row][column]=0;
						TETRISGameField[row][column-1]=TETRIS_BLOCK_MOVING;
					}

				}
			}
			else if(direction == 1)
			{
				for(column=(TETRIS_COLUMNS-2);column>=1;column--)
				{
					if(TETRISGameField[row][column]==TETRIS_BLOCK_MOVING)
					{
						TETRISGameField[row][column]=0;
						TETRISGameField[row][column+1]=TETRIS_BLOCK_MOVING;
					}
				}
			}
		}
	}
}

void TETRISAdvanceAll(int8_t startRow)
{
	int8_t rowC, columnC;
	rowC=startRow;
	for(;rowC>=0;rowC--)
	{
		for(columnC=1;columnC<(TETRIS_COLUMNS-1);columnC++)
		{
			if(TETRISGameField[rowC][columnC] == TETRIS_BLOCK)
			{
				TETRISGameField[rowC][columnC]=0;
				TETRISGameField[rowC+1][columnC]=TETRIS_BLOCK;
			}
		}
	}
}

int8_t TETRISAdvanceBlock(void)
{
	int8_t row,column,freezeTetrimino;
	freezeTetrimino = 0;
	int8_t filledBlocks=0;
	for(row=(TETRIS_ROWS-2);row>=0;row--)
	{
		filledBlocks=0;
		for(column=1;column<(TETRIS_COLUMNS-1) ;column++)
		{
			if(TETRISGameField[row][column]==TETRIS_BLOCK_MOVING)
			{
				if(row==(TETRIS_ROWS-2))
				{
					freezeTetrimino=1;
				}
			}
			else if(TETRISGameField[row][column]==TETRIS_BLOCK)
			{
				filledBlocks++;
				if(TETRISGameField[row-1][column]==TETRIS_BLOCK_MOVING)
				{
					freezeTetrimino=1;
				}
			}
		}
		if(filledBlocks==10)
		{
			for(column=1;column<(TETRIS_COLUMNS-1);column++)
			{
				TETRISGameField[row][column]=0;
			}
			TETRISScore++;
			TETRISAdvanceAll(row);
		}
	}
	for(row=(TETRIS_ROWS-2);row>=0;row--)
	{
		for(column=1;column<(TETRIS_COLUMNS-1);column++)
		{
			if(TETRISGameField[row][column]==TETRIS_BLOCK_MOVING)
			{
				if(freezeTetrimino)
				{
					TETRISGameField[row][column]=TETRIS_BLOCK;
				}
				else
				{
					TETRISGameField[row][column]=0;
					TETRISGameField[row+1][column]=TETRIS_BLOCK_MOVING;
				}
				
			}
		}
	}
	if(!freezeTetrimino)
	{
		currentTetrimino.y+=1;
	}
	return freezeTetrimino;
}

uint8_t TETRISCheck(void)
{
	uint8_t row=0,column=4;
	for(;row < 2;row++)
	{
		for(;column <8;column++)
		{
			if(TETRISGameField[row][column]==TETRIS_BLOCK)
			{
				return 0;
			}
		}
	}
	return 1;
}

void TETRISInsertBlock(uint8_t tetriminoIndex)
{
	currentTetrimino.type = tetriminoIndex;
	currentTetrimino.rotation = 0;
	currentTetrimino.y = 1;
	currentTetrimino.x = 5;

	uint8_t row,column;
	uint8_t tetrimino = pgm_read_byte(&tetriminos[tetriminoIndex]);
	for(row = 0;row<2;row++)
	{
		for(column = 4*row;column<(4+4*row);column++)
		{
			if(tetrimino & (1<<(7-column)))
			{
				TETRISGameField[row][4+(column-4*row)] = TETRIS_BLOCK_MOVING;
			}
		}
	}
}

uint8_t TETRISRotatePossible(uint8_t size)
{
	uint8_t row,column;
	uint8_t rotationPossible = 1;
	//Check if rotation is doable
	for(row = (currentTetrimino.y-1);row<(currentTetrimino.y+(size-1));row++)
	{
		for(column = (currentTetrimino.x-1);column<(currentTetrimino.x+(size-1));column++)
		{
			if((TETRISGameField[row][column] == TETRIS_EDGE) || (TETRISGameField[row][column] == TETRIS_BLOCK))
			{
				rotationPossible = 0;
				break;
			}
		}
	}
	return rotationPossible;
}

void TETRISRotateClear(uint8_t size)
{
	uint8_t row,column;
	for(row = (currentTetrimino.y-1);row<(currentTetrimino.y+(size-1));row++)
	{
		for(column = (currentTetrimino.x-1);column<(currentTetrimino.x+(size-1));column++)
		{
			TETRISGameField[row][column] = 0;
		}
	}
}

void TETRISRotate3x3(void)
{
	uint8_t row,column;
	uint8_t tetrimino = pgm_read_byte(&tetriminos[currentTetrimino.type]);
	if(currentTetrimino.rotation == 0)
	{
		for(row = (currentTetrimino.y-1);row<(currentTetrimino.y+1);row++)
		{
			for(column = 4*(row-(currentTetrimino.y-1));column<(3+4*(row-(currentTetrimino.y-1)));column++)
			{
				if(tetrimino & (1<<(7-column)))
				{
					TETRISGameField[row][(currentTetrimino.x-1)+(column-4*(row-(currentTetrimino.y-1)))] = TETRIS_BLOCK_MOVING;
				}
			}
		}
	}
	else if(currentTetrimino.rotation == 1)
	{
		for(row = (currentTetrimino.y-1);row<(currentTetrimino.y+1);row++)
		{
			for(column = 4*(row-(currentTetrimino.y-1));column<(3+4*(row-(currentTetrimino.y-1)));column++)
			{
				if(tetrimino & (1<<(7-column)))
				{
					TETRISGameField
					[(currentTetrimino.y+1)-(column-4*(row-(currentTetrimino.y-1)))]
					[(currentTetrimino.x-1)+(row-(currentTetrimino.y-1))] 
					= TETRIS_BLOCK_MOVING;
				}
			}
		}
	}
	else if(currentTetrimino.rotation == 2)
	{
		for(row = (currentTetrimino.y-1);row<(currentTetrimino.y+1);row++)
		{
			for(column = 4*(row-(currentTetrimino.y-1));column<(3+4*(row-(currentTetrimino.y-1)));column++)
			{
				if(tetrimino & (1<<(7-column)))
				{
					TETRISGameField
					[(currentTetrimino.y+1)-(row-(currentTetrimino.y-1))]
					[(currentTetrimino.x+1)-(column-4*(row-(currentTetrimino.y-1)))] 
					= TETRIS_BLOCK_MOVING;
				}
			}
		}
	}
	else if(currentTetrimino.rotation == 3)
	{
		for(row = (currentTetrimino.y-1);row<(currentTetrimino.y+1);row++)
		{
			for(column = 4*(row-(currentTetrimino.y-1));column<(3+4*(row-(currentTetrimino.y-1)));column++)
			{
				if(tetrimino & (1<<(7-column)))
				{
					TETRISGameField
					[(currentTetrimino.y-1)+(column-4*(row-(currentTetrimino.y-1)))] 
					[(currentTetrimino.x+1)-(row-(currentTetrimino.y-1))] = 
					TETRIS_BLOCK_MOVING;
				}
			}
		}
	}
}

void TETRISRotate4x4(void)
{
	uint8_t row,column;
	uint8_t tetrimino = pgm_read_byte(&tetriminos[currentTetrimino.type]);
	if(currentTetrimino.rotation == 0)
	{
		for(row = (currentTetrimino.y-1);row<(currentTetrimino.y+1);row++)
		{
			for(column = 4*(row-(currentTetrimino.y-1));column<(4+4*(row-(currentTetrimino.y-1)));column++)
			{
				if(tetrimino & (1<<(7-column)))
				{
					TETRISGameField
					[row]
					[(currentTetrimino.x-1)+(column-4*(row-(currentTetrimino.y-1)))] = TETRIS_BLOCK_MOVING;
				}
			}
		}
	}
	else if(currentTetrimino.rotation == 1)
	{
		for(row = (currentTetrimino.y-1);row<(currentTetrimino.y+1);row++)
		{
			for(column = 4*(row-(currentTetrimino.y-1));column<(4+4*(row-(currentTetrimino.y-1)));column++)
			{
				if(tetrimino & (1<<(7-column)))
				{
					TETRISGameField
					[(currentTetrimino.y+2)-(column-4*(row-(currentTetrimino.y-1)))]
					[(currentTetrimino.x)-(row-(currentTetrimino.y-1))] = TETRIS_BLOCK_MOVING;
				}
			}
		}
	}
}

void TETRISRotateBlock(void)
{
	if(currentTetrimino.type == TETRIMINO_SQUARE)
	{
		return;
	}
	else if(currentTetrimino.type == TETRIMINO_LONG)
	{
		if(TETRISRotatePossible(4))
		{
			TETRISRotateClear(4);
			currentTetrimino.rotation = (currentTetrimino.rotation == 0) ? 1 : 0;
			TETRISRotate4x4();
		}

	}
	/*Tetriminos 3x3 with rotation 0-3*/
	else if
		(
			(currentTetrimino.type == TETRIMINO_T) ||
			(currentTetrimino.type == TETRIMINO_L_LEFT) ||
			(currentTetrimino.type == TETRIMINO_L_RIGHT) 
		)
	{
		if(TETRISRotatePossible(3))
		{
			TETRISRotateClear(3);
			// currentTetrimino.rotation = (currentTetrimino.rotation == 3) ? 0 : (currentTetrimino.rotation+1);
			currentTetrimino.rotation = (currentTetrimino.rotation == 3) ? 0 : (currentTetrimino.rotation+1);
			TETRISRotate3x3();
		}

	}
	/*Tetriminos 3x3 with rotation 0-1*/
	else if
		(
			(currentTetrimino.type == TETRIMINO_DOG_LEFT) 
			|| (currentTetrimino.type == TETRIMINO_DOG_RIGHT)
		)
	{
		if(TETRISRotatePossible(3))
		{
			TETRISRotateClear(3);
			currentTetrimino.rotation = (currentTetrimino.rotation == 0) ? 1 : 0;
			TETRISRotate3x3();
		}
	}
}

void TETRISMain(void)
{
	TETRISInit();
	uint8_t buttonLastState[8]={0};
	TETRISScore = 0;
	int delayTime = 350;
	int tIndex=4;
	uint64_t startTime = MILLISGet();
	RANDOMSeed(MILLISGet());
	tIndex=RANDOMGet()%TETRIS_TETRIMINOS;
	TETRISInsertBlock(tIndex);
	_delay_ms(300);
	while(1)
	{
		if(MILLISGet()-startTime > delayTime)
		{
			if(TETRISAdvanceBlock())
			{
				if(!TETRISCheck())
				{
					LCDbufferCounter=0;
					strcpy_P(buffer,(PGM_P)pgm_read_word(&(TETRISStrings[0])));

					LCDPrintString(buffer);
					LCDPrintuint16(TETRISScore);
					LCDRender();
					_delay_ms(3000);
					break;
				}
				tIndex=RANDOMGet()%TETRIS_TETRIMINOS;
				TETRISInsertBlock(tIndex);
			}
			startTime = MILLISGet();
		}

		TETRISRender();

		// Go back to menu, added KS
		if (BUTTONGet(BUTTON2)) {
			break;
		}

		if(BUTTONGet(LEFT))
		{
			TETRISMoveBlock(-1);
		}
		else if (BUTTONGet(RIGHT)) 
		{
			TETRISMoveBlock(1);
		}
		
		if (BUTTONGet(DOWN)) 
		{
			delayTime=100;
		}
		else if(!BUTTONGet(DOWN))
		{
			delayTime=300;
		}

		if(!BUTTONGet(UP))
		{
			buttonLastState[UP]=0;
		}
		else if(BUTTONGet(UP) && (buttonLastState[UP]==0))
		{
			buttonLastState[UP]=1;
			TETRISRotateBlock();
		}
		_delay_ms(70);
	}
}
