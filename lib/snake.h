#ifndef SNAKE_H
#define SNAKE_H

#include "buttons.h"
#include <avr/pgmspace.h>
#include "lcd.h"
#include "random.h"
#include "millis.h"


#define SNAKE_UP 0
#define SNAKE_DOWN 1
#define SNAKE_LEFT 2
#define SNAKE_RIGHT 3
#define SNAKE_UP_LEFT 4
#define SNAKE_DOWN_RIGHT 5
#define SPRITE_SIZE 4
#define LCD_X 84
#define LCD_Y 48
#define PLAYGROUND_UPPER_BOUND_X 80
#define PLAYGROUND_LOWER_BOUND_X 4
#define PLAYGROUND_UPPER_BOUND_Y 44 
#define PLAYGROUND_LOWER_BOUND_Y 12
#define SNAKE_SIZE ((PLAYGROUND_UPPER_BOUND_X - PLAYGROUND_LOWER_BOUND_X) / 4) * ((PLAYGROUND_UPPER_BOUND_Y - PLAYGROUND_LOWER_BOUND_Y) / 4)


typedef struct snake {
	int8_t x;
	int8_t y;
	int8_t lastMoveDir;
	int8_t currentDir;
	Sprite *sprite;
} Snake;

typedef struct food {
	int8_t x;
	int8_t y;
	int8_t points;
	int8_t available;
} Food;

void SNAKEInit(Snake *snake);
void SNAKEMain(void);
void SNAKEhandleInputs(uint8_t *direction);
void SNAKEmoveHead(Snake *snakeHead, uint8_t direction);
void SNAKEbodyFollow(Snake *snake);
void SNAKEplaceSnake(Snake *snake);
uint8_t SNAKEcheckDeath(Snake *snake);
void SNAKEgenerateFood(Food *snack, Snake *snake);
void SNAKEeatFood(Food *snack, Snake *snake);
void SNAKEdeathScreen(Snake *snake);
void SNAKEPrintScore(uint16_t value);
uint8_t SNAKEgameWin(Snake *snake);

uint8_t snakeLength;
uint8_t headSide;
uint8_t moved;
uint8_t startX;
uint8_t startY;
uint16_t baseSpeed;
uint64_t startTime;
uint16_t score;


#endif