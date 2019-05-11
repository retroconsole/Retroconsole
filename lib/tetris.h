#ifndef TETRIS_H
#define TETRIS_H
#include "buttons.h"
#include "lcd.h"
#include <avr/pgmspace.h>
#include "led.h"
#include "millis.h"
#include "random.h"

/*One block size is 3x3 pixels*/
#define TETRIS_ROWS 16
#define TETRIS_COLUMNS 12
#define TETRIS_BLOCK_LENGTH 3

#define TETRIS_LEFT_EDGE 		3*8-1
#define TETRIS_RIGHT_EDGE 	3*20

//Block types on gamefield
#define TETRIS_EMPTY 			0
#define TETRIS_EDGE 			1
#define TETRIS_BLOCK 			2
#define TETRIS_BLOCK_MOVING 	3

#define TETRIS_TETRIMINOS 7
//Tetrimino types
#define TETRIMINO_T 			0
#define TETRIMINO_SQUARE 		1
#define TETRIMINO_LONG 			2
#define TETRIMINO_L_RIGHT 		3
#define TETRIMINO_L_LEFT 		4
#define TETRIMINO_DOG_LEFT 		5
#define TETRIMINO_DOG_RIGHT 	6

typedef struct _tetrimino
{
	uint8_t type;
	uint8_t x;
	uint8_t y;
	uint8_t rotation;
} Tetrimino;

void TETRISMain(void);
void TETRISInit(void);
void TETRISRender(void);
void TETRISMoveBlock(int8_t direction);
void TETRISAdvanceAll(int8_t startRow);
int8_t TETRISAdvanceBlock(void);
uint8_t TETRISCheck(void);
void TETRISInsertBlock(uint8_t tetriminoIndex);
uint8_t TETRISRotatePossible(uint8_t size);
void TETRISRotateClear(uint8_t size);
void TETRISRotate3x3(void);
void TETRISRotate4x4(void);
void TETRISRotateBlock(void);
uint16_t TETRISScore;

#endif