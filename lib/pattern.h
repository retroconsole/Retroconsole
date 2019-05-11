#ifndef PATTERN_H
#define PATTERN_H

#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include "buttons.h"
#include "lcd.h"
#include "romaddresses.h"
#include "millis.h"
#include "random.h"

void PATTERNMain();
void PATTERNInit();
void PATTERNRender(uint8_t selectedBlock);
void PATTERNPrintScore();

uint16_t PATTERNSeed;
uint16_t PATTERNScore;
uint8_t boxValue;
#define PATTERN_EDGE_LEN 16
#endif