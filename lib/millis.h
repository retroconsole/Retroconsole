#include <util/delay.h>
// #include <util/atomic.h>
#include <avr/interrupt.h>

#define PRESCALER 256UL //20MHz / (CS02) = 78.125kHz
#define MILLIS_TICKS ((F_CPU / PRESCALER) / 1000UL) //uint8_t value, so has to be below 255

static volatile uint64_t _millis;

void MILLISInit();
uint64_t MILLISGet();
