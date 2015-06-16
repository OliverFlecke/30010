#include <eZ8.h>
#include <sio.h>
#include "display.h"
#include "timer.h"


void initKeyPD3() {
	PDDD = 0x08; 	// Low nipple input on bit 3	
	PDADDR = 0;		// Protection of port G
}


void main() {
	char keyCounter = 0;
	showBinaryDisplay0(0);		// Clears the first display
	init_uart(_UART0, _DEFFREQ, _DEFBAUD); 

	initTimer0();	

	initKeyPD3();

	while(1==1){
		if ((PDIN & 0x08) == 0) {
			long bounceCount;
			
			keyCounter++;			
			printf("%d\n", keyCounter);
			showBinaryDisplay0(keyCounter);

			bounceCount = getCounter0();
			while( ((PDIN & 0x08) == 0) || (bounceCount > getCounter0() - 5 )){ 	// Delay to avoid bounce (100 ms) and while key is pressed
			}
		}
	}	
}
