#include <eZ8.h>

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
