
#include <eZ8.h>   // special encore constants, macros and flash functions
#include <sio.h>	 // special encore serial i/o functions
#include "lut.h"

void main(){
	init_uart(_UART0, _DEFFREQ, _DEFBAUD);  // set-up UART0 to 57600, 8n1

	printf("%d %d %d %d\n%d",sin(0),sin(45),sin(-78),sin(649),SIN[63]);
	
	while(1==1){}
}
