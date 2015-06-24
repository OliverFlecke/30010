#include "numberformat.h"

/*
	Convert a long 16.16 format to a normal integer (short)
*/
short roundToShort(long x) {
	if(x & 0x00008000)
		return (x >> 16) + 1;	// If the first decimal point is greather than or equal to 5, the number is rounded up
	else
		return (x >> 16);		// Else the number is rounded down
}
