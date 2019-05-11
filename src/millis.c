#include "millis.h"

ISR(TIMER0_COMPA_vect)
{
	_millis++;
}

void MILLISInit(void)
{
	_millis = 0;
	TCCR0A = (1 << WGM01); //CTC Mode
	TCCR0B = (1 << CS02); //Prescaler 256UL; 20MHz/256 == 78.125kHz
	OCR0A = MILLIS_TICKS; //Compare 1 millisecond worth of ticks

	TIMSK0 = (1 << OCIE0A); //Compare vector enable
	sei(); //Interrupts enable
}

uint64_t MILLISGet(void)
{
	return _millis;
}
