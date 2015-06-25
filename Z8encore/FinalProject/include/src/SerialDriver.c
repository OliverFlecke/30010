#include "serialDriver.h"
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
	Setup serial communication
*/
void initSerial() {
	init_uart(_UART0, _DEFFREQ, _DEFBAUD);
}

/*
	Set the cursor at the default position
*/
void homeCursor() {
	setCursor(1,31);
}

/*
	Draw boundaries of the game 
*/
void drawBoundaries() {
	short i;
	setColor(solidColor, backgroundColor);	

	setCursor(1, 1);
	printf("%c", 220);	// Print upperleft corner
	for (i = 1; i <= width; i++) // Print top of the boundaries
		printf("%c", 220);
	printf("%c", 220);	// Print upperright corner

	// Print sides
	for (i = 2; i < height; i++) {
		setCursor(1, i);		// Set the cursor to the left side 
	    printf("%c", 219);	
		setCursor(width + 2, i); // Set the cursor to the right side
		printf("%c", 219);
	}
	homeCursor();
}

/*
	Draw the striker
*/
void drawStriker(char strikerWidth, unsigned char strikerPosition, char direction) {
	char i; 

	setColor(strikerColor, backgroundColor);
	if (direction == 1) {		// Move the striker right
		// Delete the left most character
		drawBlankSpace(strikerPosition - strikerWidth/2, height - 2);

		// Print new character to the right of the striker
		setCursor(strikerPosition + strikerWidth/2 + 3, height);
		printf("%c", 223);
	} 
	else if (direction == -1) {		// Move the striker left
		// Delete the right most character 
		drawBlankSpace(strikerPosition + strikerWidth/2, height - 2);

		setCursor(strikerPosition - strikerWidth/2 + 1 , height);
		printf("%c", 223);
	} 
	else if (direction == 0) {
		setCursor(0, height);
		clearLine();
		setCursor(0, height + 1);
		clearLine();

		setCursor(strikerPosition + 2 - strikerWidth/2, height);
		for (i = 0; i < strikerWidth; i++) {
			printf("%c", 223);
		}
		// Draw game stats text
		setCursor(0, 33);	
		setColor(redTextColor, backgroundColor);
		printf("Remaning Obstructions:        ");
		printf("Balls:        ");
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

// Array to store the last 8 positions of the ball
short ball[8][2];

/*
	Update the balls position in the game
*/
void updateBallOnScreen(struct Vector *nextPosition){
	char i;
	// Delete the last ball position from the array
	setCursor(ball[7][0] + 2, ball[7][1] + 2);
	printf("%c", 32);

	// Update the array
	for (i = 6; i >= 0; i--) {
		ball[i + 1][0] = ball[i][0];
		ball[i + 1][1] = ball[i][1];
	}

	// Set the new position at the end of the array
	ball[0][0] = roundToShort(nextPosition->x);
	ball[0][1] = roundToShort(nextPosition->y);

	// Draw new position
	setColor(ballColor, backgroundColor);
	setCursor(ball[0][0] + 2, ball[0][1]+ 2);
	printf("%c", 219);

	// set cursor in the corner
	homeCursor();
}

/*
	Draw an obstruction at the passed position
	This function returns the number of life the drawn obstruction has
*/
char drawSingleObstruction(char arrayPosition, long bitPosition, long current) {
	char k;
	// Set the cursor at the start of the obstruction
	setCursor(((30 - bitPosition) << 2) + 2 , arrayPosition + 2);

	// Draw a blue, soild block
	if (((current >> bitPosition) & 0x3) == 0x3) {
		setColor(solidColor, backgroundColor);
		for (k = 0; k < 8; k++) 
			printf("%c", 219);
		return 0;
	}
	// Draw a green obstruction with two life
	else if (((current >> bitPosition) & 0x2) == 0x2) {
		setColor(block2LifeColor, backgroundColor);
		for (k = 0; k < 8; k++) 
			printf("%c", 178);
		return 2;
	}
	// Draw a red obstruction with one life
	else if (((current >> bitPosition) & 0x1) == 0x1) {
		setColor(block1LifeColor, backgroundColor);
		for (k = 0; k < 8; k++)
			printf("%c", 176);
		return 1;
	}
	// Draw a blank space instead of an obstruction
	else {
		printf("        ");
		return 0;
	}
}

/*
	Draw the game stats in the lower right cornor
*/
void drawGameStats(unsigned char health, unsigned long obstructions) {
	setColor(redTextColor, backgroundColor);\
	
	// Print the number of obstructions left
	setCursor(24, 33);
	printf("%04d", obstructions);

	// Print the number of remaning health 
	setCursor(38, 33);
	printf("%d", health);
}