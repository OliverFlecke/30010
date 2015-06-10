
#include <eZ8.h>   // special encore constants, macros and flash functions
#include <sio.h>	 // special encore serial i/o functions
#include "lut.h"
#include "numberformat.h"
#include "vector.h"

void main(){
	struct TVector v;
	initVector(&v);

	init_uart(_UART0, _DEFFREQ, _DEFBAUD);  // set-up UART0 to 57600, 8n1

	printFixedPoint1616(convert1616(sin(-10)));	// print sin(-10 degrees)
	printFixedPoint1616(convert1616(cos(-10)));	// print cos(-10 degress)

	rotate(&v, -10);	// rotate vector v -10 degress
	printFixedPoint1616(convert1616(v.x));	// print x-coordinate
	printFixedPoint1616(convert1616(v.y));	// print y-coordinate

	while(1==1){}
}

