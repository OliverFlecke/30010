#include <eZ8.h>
#include <sio.h>
#include "charset.h"
#include "display.h"

char videoBuffer[5][6];

void updateDisplay(char character, char col, char display) {
	PEDD = 0x00;
	PGDD = 0x00; 
	
	PEADDR = 0;
	PGADDR = 0;

	PGOUT = videoBuffer[character][col]; 
	switch(col) {
		case 4:
			PEOUT = 0x1E;	
			break;
		case 3: 
			PEOUT = 0x1D;
			break;
		case 2: 
			PEOUT = 0x1B;
			break;
		case 1: 
			PEOUT = 0x17;
			break;
		case 0:
			PEOUT = 0x0F;
			break;
		default: 
			break;
	}
	clockDisplay(display);
}

/*
	Update the videobuffer to create scroll effect
*/
void scrollVideoBuffer() {
	
}

void main() {
	char i, j, scrollCounter = 0; 
	init_uart(_UART0, _DEFFREQ, _DEFBAUD);

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			videoBuffer[j][i] = character_data[45 + j][i];
		}
	}	

	initTimer0();
	while(1 == 1) {		
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) 
				updateDisplay(j, i, j);
		}
		if (getCounter0() > scrollCounter + 10 ) {
			scrollCounter = getCounter0();
			scrollVideoBuffer();
		}
	}	
}
