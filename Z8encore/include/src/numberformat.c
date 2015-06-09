#include <sio.h>
#include "numberformat.h"

// Tests
// void main() {
// 	printFix(expand(0xC18E));
// 	printFix(expand(0x2CB2));
// }

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
	Converts 2.14 format to 16.16
*/
long expand1616(long i) {
	if ((i & 0x8000) != 0) {
		i = i & 0x7FFF;
		return (i << 2) | 0xFFFF0000;
	} else
		return i << 2;
}