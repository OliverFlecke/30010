#include "keyDriver.h"

/*
	Setup key PD3 - Left key
*/
void initKeyPD3() {
	PDCTL |= 0x08; 	// Bit 4 set to input	
	PDADDR = 0;		// Protection of port D
}

/*
	Setup key PF6 - Right key
*/
void initKeyPF6() {
	PFCTL |= 0x40; 	// Bit 7 set to input
	PFADDR = 0;		// Protection of port F
}

/*
	Setop key PF7
*/
void initKeyPF7() {
	PFCTL |= 0x80; 	// Bit 8 set to input
	PFADDR = 0; 	// Protection of port F
}

/*
	Initialize all keys
*/
void initKeys() {
	initKeyPD3();
	initKeyPF6();
	initKeyPF7();
}

/*
	Check if left key is pressed
*/
char isLeftKeyPressed() {
	if ((PDIN & 0x08) == 0)
		return 1;
	else 
		return 0;
}

/*
	Check if the right key is pressed
*/
char isRightKeyPressed() {
	if ((PFIN & 0x80) == 0) 
		return 1;
	else 
		return 0;
}

char isEnterKeyPressed(){
	if ((PFIN & 0x40) == 0)
		return 1;
	else 
		return 0;
}