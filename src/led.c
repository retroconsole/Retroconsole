#include "led.h"
void LEDInitialize(void)
{
	DDRC |= (1 << LED1) | (1 << LED2); //Ouput leds
	PORTC |= (1 << LED1) | (1 << LED2); //Leds off
}
void LEDSet(uint8_t led,uint8_t state)
{
	if(state == 1)
	{
		PORTC &= ~(1 << led);
	}
	else if(state == 0)
	{
		PORTC |= (1 << led);
	}
	
}
