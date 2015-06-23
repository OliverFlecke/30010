#include "numberformat.h"
#include <sio.h>

/*
	Prints fixedpoint 16.16 number 
*/
void printFixedPoint1616(long i) {
	if ((i & 0x80000000) != 0) {
		printf("-");
		i = ~i+1;
	}

	printf("%ld.%04ld", i >> 16, 10000 * (unsigned long) (i & 0xffff) >> 16);
}

/*
	Converts a normal number to 18.14 format
*/
long convert1814(long i) {
	return i << 14;
}


/*
	Converts 18.14 format to 16.16
*/
long convert1616(long i) {
	return i << 2;
}


/*
	Convert a long 16.16 format to a normal integer (short)
*/
short roundToShort(long x) {
	if(x & 0x00008000)
		return (x >> 16) + 1;	// If the first decimal point is greather than or equal to 5, the number is rounded up
	else
		return (x >> 16);		// Else the number is rounded down
}
