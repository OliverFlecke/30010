#include "game.h"

short ballUpdatePeriodTime = 40;
short strikerUpdatePeriod = 20;
short strikerPosition = WIDTH/2;
char strikerWidth = 11;		// Must be an odd number
short angle = 45;			// Start angle. Must match start direction vector
long sqrt2half = 0xB504; // Binary form = 1011010100000100;

long level[] = {
	0x000000000, 0x000000000, 0x02AAAAAA8, 0x000000000, 
	0x004100410, 0x000000000, 0x003C003C0, 0x000000000, 
	0x028A28A28, 0x014514514, 0x000000000, 0x0030C30C0, 
	0x000000000, 0x014005554, 0x000000000, 0x000000000, 
	0x000000000, 0x000000000, 0x000000000, 0x000000000, 
	0x000000000, 0x000000000, 0x000000000, 0x000000000, 
	0x000000000, 0x000000000, 0x000000000, 0x000000000, 
	0x000000000, 0x000000000, 0x000000000, 0x000000000
};

/*
	Calculate the position for the ball
*/
void calculateNextPosition(struct Vector *position , struct Vector *direction , struct Vector *nextPosition){
	nextPosition->x = position->x + direction->x;
	nextPosition->y = position->y + ((direction->y) >> 1);	// times 1/2 for correction of the uneven pixel density of the console
}

void mainGame() {
	// initialize vectors
	struct Vector direction;
	struct Vector currentPosition;
	struct Vector nextPosition;
	initVector(&direction);
	initVector(&currentPosition);
	initVector(&nextPosition);
	direction.y = sqrt2half;
	direction.x = sqrt2half;
	currentPosition.x = 40 << 16;
	currentPosition.y = 19 << 16;
	setColor(36, 40);

	clearScreen();
	drawBoundaries();
	drawObstructions();
	drawStriker(strikerWidth, strikerPosition, 0);

	// Init timers and keys
	initKeys();
	initTimer0();
	while (1 == 1) { 
		if (getTimer0() >= strikerUpdatePeriod) {
			strikerUpdatePeriod += 25;
			if (isLeftKeyPressed() == 1 && strikerPosition > strikerWidth/2) {
				drawStriker(strikerWidth, strikerPosition, -1);
				strikerPosition--;
			} 
			else if (isRightKeyPressed() == 1 && strikerPosition < WIDTH - 1 - strikerWidth/2) {
				drawStriker(strikerWidth, strikerPosition, 1); 	
				strikerPosition++;
			}
		}

		if (getTimer0() >= ballUpdatePeriodTime) {
			resetTimer0();
			strikerUpdatePeriod = 0;

			// Calculate the new position
			calculateNextPosition(&currentPosition,&direction,&nextPosition);	
			updateDirectionOnCollision(&currentPosition,&direction,&nextPosition);

			updateBallOnScreen(&nextPosition);
			currentPosition = nextPosition;
		}
	}
}

void updateDirectionOnCollision(struct Vector *position , struct Vector *direction , struct Vector *nextPosition) {
	// Check if the the next postion is a collision with the left or right side boundaries
	if (roundToShort(nextPosition->x) < 0 || roundToShort(nextPosition->x) >= WIDTH) {
		direction->x = -direction->x;
		calculateNextPosition(position, direction, nextPosition);
	}
	// Check for collision with the top boundary
	else if (roundToShort(nextPosition->y) < 0) {
		direction->y = -direction->y; 
		calculateNextPosition(position, direction, nextPosition);
	} 

	// Check obstuction Collision
	obstuctionCollision(position, direction, nextPosition);
	// Debugging
	// homeCursor();
	// printf("s: %d  [%d, %d] - [%d, %d]\n", strikerPosition, roundToShort(position->x), roundToShort(position->y), roundToShort(nextPosition->x), roundToShort(nextPosition->y));
	
	// Check for collision with the striker
	if (roundToShort(nextPosition->y) == HEIGTH - 1) {
		unsigned short x = roundToShort(nextPosition->x);	// Calculate a rounded value of the x coordinate
		// Check if the ball is inside the striker
		if (x >= strikerPosition - strikerWidth/2 && x <= strikerPosition + strikerWidth/2) {
			direction->y = -direction->y;

			// Change direction vector on right side
			if (x > strikerPosition) {
				rotate(direction, angle/2);
				if (direction->x > 0) 
					angle /= 2;
				else 
					angle += angle/2;
			} 
			// Change direction vector on left side
			else if (x < strikerPosition) {
				rotate(direction, -angle/2);
				
				if (direction->x > 0) 
					angle += angle/2; 
				else 
					angle /= angle/2;
			}
		}

		// Calculate the next position based on the new direction
		calculateNextPosition(position, direction, nextPosition);
	}
	// Check for passing through the lower boundary
	else if (roundToShort(nextPosition->y) >= HEIGTH) {
		// Game over
		stopTimer0();
		setCursor(60, 16);
		printf("GAME OVER");
	}
}

/*
	Draw game obstruction on the game grid
*/
void drawObstructions() {
	char i, j;
	// Loop through each row
	for (i = 0; i < HEIGTH; i++) 
		for (j = 30; j >= 0; j -= 2) 
			drawSingleObstruction(i, j, level[i]);
}

/*

*/
void obstuctionCollision(struct Vector *position , struct Vector *direction , struct Vector *nextPosition) {
	char arrayPosition = roundToShort(nextPosition->y); 
	char bitPosition = (30 - ((roundToShort(nextPosition->x) >> 3) << 1)); 	// Divide by 8 to get the correct block. Times 2 to get the correct number of bitshifts 
	
	long row = level[arrayPosition];						// Get the row in the level grid
	row = row >> bitPosition;

	if ((row & 0x3) != 0) {
		direction->y = -direction->y;
		calculateNextPosition(position, direction, nextPosition);

		updateObstructionOnHit((row & 0x3) , arrayPosition, bitPosition);
	}
}

void updateObstructionOnHit(char value, char arrayPosition, long bitPosition){
	if(value > 2 || value < 1){
		// solid block, do nothing
	}
	else {
		level[arrayPosition] -= 1 << bitPosition;	// subtract 1 from the value of the hit obstruction's "life"
		drawSingleObstruction(arrayPosition, bitPosition, level[arrayPosition]);
	}
}