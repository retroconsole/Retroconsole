#ifndef BUTTONS_H
#define BUTTONS_H

#include <avr/io.h>

#define BUTTON1 PD0
#define BUTTON2 PD1
#define LEFT PD2
#define UP PD3
#define DOWN PD4
#define RIGHT PD5
#define BUTTON7 PD6
#define BUTTON8 PD7

void BUTTONSInitialize(void);
uint8_t BUTTONGet(uint8_t button);

#endif