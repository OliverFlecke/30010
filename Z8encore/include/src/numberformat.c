#include <sio.h>
#include "numberformat.h"

/*
	Prints fixedpoint 16.16 number 
*/
void printFixedPoint1616(long i) {
	if ((i & 0x80000000) != 0) {
		printf("-");
		i = ~i+1;
	}

	printf("%ld.%04ld\n\n", i >> 16, 10000 * (unsigned long) (i & 0xffff) >> 16);
}

/*
	Converts a number normal number to 18.14 format
*/
long convert1814(long i) {
	return i << 14;
}


/*
	Converts 18.14 format to 16.16
*/
long convert1616(long i) {
/*	if ((i & 0x80000000) != 0) {
		i = i & 0x7FFFFFFF;
		return (i << 2) | 0xFFFF0000;
	} else
*/		return i << 2;
}