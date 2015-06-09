
#include <eZ8.h>   // special encore constants, macros and flash functions
#include <sio.h>	 // special encore serial i/o functions
#include "lut.h"
#include "numberformat.h"

void main(){
	init_uart(_UART0, _DEFFREQ, _DEFBAUD);  // set-up UART0 to 57600, 8n1

	printFixedPoint1616(expand1616(sin(45)));	// print sin(45 degrees)
	printFixedPoint1616(expand1616(cos(45)));	// print cos(45 degress)

	while(1==1){}
}


