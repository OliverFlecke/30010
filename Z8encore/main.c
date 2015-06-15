#include <sio.h>
#include <eZ8.h>
#include "vector.h"	
#include "numberformat.h"
#include "Timer.h"
#include "SerialDriver.h"

void initSerial() {
	init_uart(_UART0, _DEFFREQ, _DEFBAUD);
}

void calculateNextPosition(struct Vector *postition , struct Vector *direction , struct Vector *nextPosition){
	nextPosition->x = postition->x + direction->x;
	nextPosition->y = postition->y + direction->y;
}

void main() {
	
	// initialize vectors
	struct Vector direction;
	struct Vector currentPosition;
	struct Vector nextPosition;
	initVector(&direction);
	initVector(&currentPosition);
	initVector(&nextPosition);
	
	initSerial();

	clearScreen();
	drawBoundaries();


	initTimer0();
	while (1 == 1) { 
		if (getTimer0() >= 1000) {
			calculateNextPosition(&currentPosition,&direction,&nextPosition);	
			updateBallOnScreen(&currentPosition,&nextPosition);
			currentPosition = nextPosition;

		//	printf("%d",getTimer0());
//			printf("%d\n", getTimer0());

			
//			setCursor(10, 10);
//			printf("%c%c%c%c", 219, 219, 219, 219);
			
//			drawStriker(0);
//			drawStriker(1);
			
//			drawBall(20,20);
			
//			setCursor(1, 32);

			resetTimer0();
		}
	}
/*	*/
}

