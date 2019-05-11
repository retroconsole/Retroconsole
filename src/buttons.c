#include "buttons.h"
void BUTTONSInitialize(void)
{
	DDRD=0x00;	//All as OUTPUT
	PORTD = 0xFF;	//PULLUP PORTD all PINS
}

uint8_t BUTTONGet(uint8_t button)
{
	return(!(PIND & (1 << button)));
}