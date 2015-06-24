#include "level.h"

/*
	Move data from ROM into RAM
*/
void loadLevelFromROM(long rom *src, long *dest) {
	char i;
	// Move the data in a long into the RAM 
	for (i = 0; i < 31; i++)
		*dest++ = *src++;
}