#include <eZ8.h>   // special encore constants, macros and flash functions
#include <sio.h>	 // special encore serial i/o functions
#include <string.h>
#include "ansi.h"

void main(){
	char str[] = "Window title";
	int size = sizeof(str)/sizeof(str[0]);
	init_uart(_UART0, _DEFFREQ, _DEFBAUD);  // set-up UART0 to 57600, 8n1
	
	clearScreen();
	setColor(30,47);
	window(5,5,25,25,str,size,'a');

	while(1==1){}
}
