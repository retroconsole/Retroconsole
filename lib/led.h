#ifndef LED_H
#define LED_H

#include <avr/io.h>
#define LED1 PC1
#define LED2 PC2
void LEDInitialize(void);
void LEDSet(uint8_t led,uint8_t state);

#endif