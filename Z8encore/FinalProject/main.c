#include "SerialDriver.h"
#include <sio.h>
#include <eZ8.h>
#include "Timer.h"

void initSerial() {
	init_uart(_UART0, _DEFFREQ, _DEFBAUD);
}


void main() {
	initSerial();

	initTimer0();
	while (1 == 1) { 
		if (getTimer0() == 1000) {
			printf("%d\n", getTimer0());

			clearScreen();
			drawBoundaries();
			
			setCursor(10, 10);
			printf("%c%c%c%c", 219, 219, 219, 219);
			
			drawStriker(0);
			drawStriker(1);
			
			drawBall(20,20);
			
			setCursor(1, 32);

			resetTimer0();
		}
	}
/*	*/
}

