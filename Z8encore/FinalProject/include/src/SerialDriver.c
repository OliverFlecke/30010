#include "SerialDriver.h"
#include "vector.h"
#include "numberformat.h"

/*
	Clears the screen
*/
void clearScreen() {
	printf("%c[2J", ESC);
}

/*
	Clear line
*/
void clearLine() {
	printf("%c[K", ESC);
}

/*
	Set the cursor position
*/
void setCursor(short x, short y){
	printf("%c[%d;%dH", ESC, y, x);
}

/*
	Set color of the terminal
*/
void setColor(short fg, short bg) {
	printf("%c[%u;%um", ESC, fg, bg);
}

/*
	Draw boundaries of the game 
*/
void drawBoundaries() {
	short i;
	setCursor(1, 1);
	printf("%c", 220);	// Print upperleft corner
	for (i = 1; i <= width; i++){
		printf("%c", 220);
	}
	printf("%c", 220);	// Print upperright corner

	// Print sides
	for (i = 2; i <= height; i++) {
		setCursor(1, i);
	    printf("%c", 219);
		setCursor(width + 2, i);
		printf("%c", 219);
	}
	homeCursor();
}

/*
	Draw the striker
*/
void drawStriker(char strikerWidth, unsigned char strikerPosition, char direction) {
	char i; 

	if (direction == 1) {		// Move the striker right
		// Delete the left most character
		drawBlankSpace(strikerPosition - strikerWidth/2, height - 1);

		// Print new character to the right of the striker
		setCursor(strikerPosition + strikerWidth/2 + 3, height + 1);
		printf("%c", 223);
	} 
	else if (direction == -1) {		// Move the striker left
		// Delete the right most character 
		drawBlankSpace(strikerPosition + strikerWidth/2, height - 1);

		setCursor(strikerPosition - strikerWidth/2 + 1 , height + 1);
		printf("%c", 223);
	} 
	else if (direction == 0) {
		setCursor(strikerPosition + 2 - strikerWidth/2, height + 1);
		for (i = 0; i < strikerWidth; i++) {
			printf("%c", 223);
		}
	}
	homeCursor();
}

/*
	Delete the passed position
*/
void drawBlankSpace(short x, short y) {
	setCursor(x + 2, y + 2);
	printf("%c", 32);
}

/*
	Update the balls position in the game
*/
void updateBallOnScreen(struct Vector *currentPosition , struct Vector *nextPosition){
	// Draw next position
	setCursor(roundToShort(nextPosition->x) + 2, roundToShort(nextPosition->y) + 2);
	printf("%c", 111);

	// Erase last postion by drawing a blank space
	setCursor(roundToShort(currentPosition->x) + 2, roundToShort(currentPosition->y) + 2);
	printf("%c", 32);

	// set cursor in the corner
	homeCursor();
}

/*
	Setup serial communication
*/
void initSerial() {
	init_uart(_UART0, _DEFFREQ, _DEFBAUD);
}

/*
	Set the cursor at the default position
*/
void homeCursor() {
	setCursor(1,1);
}