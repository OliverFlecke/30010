#include "displayDriver.h"

char videoBuffer[4][5];

/*
	Clock display 0
*/
void clockDisplay0(){
	PEOUT &= ~0x80;	// Set clock pin low
	PEOUT |= 0x80;	// Set clock pin high
	PEOUT &= ~0x80; // Set clock pin low
}

/*
	Clock display 1
*/
void clockDisplay1() {
	PGOUT &= ~0x80;
	PGOUT |= 0x80;
	PGOUT &= ~0x80;
}

/*
	Clock display 2
*/
void clockDisplay2() {
	PEOUT &= ~0x20;
	PEOUT |= 0x20;
	PEOUT &= ~0x20;
}

/*
	Clock display 3
*/
void clockDisplay3() {
	PEOUT &= ~0x40;
	PEOUT |= 0x40;
	PEOUT &= ~0x40;
}

/*
	Clock all displays
*/
void clockDisplays() {
	clockDisplay0();
	clockDisplay1();
	clockDisplay2();
	clockDisplay3();
}

void clockDisplay(char display) {
	switch (display) {
		case 0:
			clockDisplay0();
			break;
		case 1: 
			clockDisplay1();
			break;
		case 2: 
			clockDisplay2();
			break;
		case 3: 
			clockDisplay3();
			break;
	}
}

/*
	Show a number on the first column
*/
void showBinaryDisplay0(char i){
	PEDD = 0x00;		// Set port E as output
	PGDD = 0x00;		// Set port G as output

	PEADDR = 0;
	PGADDR = 0;
	
	// Display number on column 4
	PEOUT = 0x0F;			// Activate col 4
	PGOUT = i & (~0x80);	// Display the passed char on column 4

	clockDisplays();
}


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

void insertInVideoBuffer(long value){
	short i,j,tempDigit;

	value /= 1000;

	for (j = 0; j < 4; j++){

		switch (j){
			case 0:
				tempDigit = value/1000;		// get the leftmost digit
			//	setCursor(10,20);
				break;
			case 1:
				tempDigit = (value/100)%10;	// get the second to left digit
			//	setCursor(14,20);
				break;
			case 2:
				tempDigit = (value/10)%10;	// get the second to right digit
			//	setCursor(18,20);
				break;
			case 3:
				tempDigit = value%10;		// get the rightmost digit
			//	setCursor(22,20);
				break;
			default:
				break;
		}
		//printf("%d",tempDigit);

		for (i = 0; i < 5; i++) {
			videoBuffer[j][i] = character_data[16 + tempDigit][i];
		}
	}
}