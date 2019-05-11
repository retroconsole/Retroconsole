#include "random.h"
//From C programming book
unsigned long int next = 1;
unsigned int RANDOMGet(void)
{
	next=next*1103515245 + 12345;
	return (unsigned int)(next / 65536)%32768;
}
void RANDOMSeed(unsigned int seed)
{
	next = seed;
}