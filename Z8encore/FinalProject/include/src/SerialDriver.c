#include "SerialDriver.h"
#include "vector.h"
#include "numberformat.h"

// The x coordiante of the striker
short strikerPosition;

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
	printf("%c",218);	// Print upperleft corner
	for (i = 1; i <= width; i++){
		printf("%c", 196);
	}
	printf("%c",191);	// Print upperright corner

	// Print sides
	for (i = 2; i <= height - 1; i++) {
		setCursor(1, i);
	    printf("%c", 179);
		setCursor(width + 2, i);
		printf("%c", 179);
	}
	strikerPosition = width/2;
}

/*
	Draw the striker
*/
void drawStriker(char direction) {
	char i; 

	if (direction == 1) {		// Move the striker right
		// Delete the left most character
		drawBlankSpace(strikerPosition - 2, height);
		// setCursor(strikerPosition - 2, height);		
		// printf("%c", 32);
		strikerPosition++;

		// Print new character to the right of the striker
		setCursor(strikerPosition + 2, height);
		printf("%c", 223);
	} 
	else if (direction == -1) {		// Move the striker left
		// Delete the right most character 
		drawBlankSpace(strikerPosition + 2, height);
		// setCursor(strikerPosition + 2, height);
		// printf("%c", 32);
		strikerPosition--;

		setCursor(strikerPosition - 2, height);
		printf("%c", 223);
	} 
	else if (direction == 0) {
		setCursor(strikerPosition - 2, height);
		for (i = 0; i < 5; i++) {
			printf("%c", 223);
		}
	}
}

/*
	Draw the ball in the game grid

	void drawBall(short x, short y) {
	setCursor(x + 2, y + 2);
	printf("%c", 111);
}
*/

/*
	Delete the passed position
*/
void drawBlankSpace(short x, short y) {
	setCursor(x + 2, y + 2);
	printf("%c", 32);
}


void updateBallOnScreen(struct Vector *currentPosition , struct Vector *nextPosition){
	// Draw next position
	setCursor(roundToShort(nextPosition->x) + 2, roundToShort(nextPosition->y) + 2);
	printf("%c", 111);

	// Erase last postion by drawing a blank space
	setCursor(roundToShort(currentPosition->x) + 2, roundToShort(currentPosition->y) + 2);
	printf("%c", 32);

	// set cursor in the corner
	setCursor(1,1);
}
