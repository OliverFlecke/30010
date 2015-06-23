#include "game.h"

unsigned short strikerPosition;
char strikerWidth = 11;		// Must be an odd number
short angle;				// Start angle. Must match start direction vector
unsigned long score = 0;
unsigned char health;
char displayCol = 0;
char game = 0;
long level[32];



/*
	Calculate the position for the ball
*/
void calculateNextPosition(struct Vector *position , struct Vector *direction , struct Vector *nextPosition){
	nextPosition->x = position->x + direction->x;
	nextPosition->y = position->y + ((direction->y) >> 1);	// times 1/2 for correction of the uneven pixel density of the console
}

void mainGame() {
	// Game variables 
	char chosenLevel = 1;
	const unsigned char menuKeyDebounce = 100;
	short ballUpdatePeriodTime = 40;
	short strikerUpdatePeriod = 20;
	short displayUpdatePeriod = 1;
	short videoBufferUpdate = 1000;
	

	// initialize vectors
	struct Vector direction;
	struct Vector currentPosition;
	struct Vector nextPosition;
	initVector(&direction);
	initVector(&currentPosition);
	initVector(&nextPosition);
	
	// Clears the screen and draws the boundaries 
	clearScreen();
	setColor(36, 40);
	drawBoundaries();

	// Init keys
	initKeys();
	initTimer0();
	
	while (1 == 1) {
		// Print out menu
		setCursor(60,12);
		printf("START GAME");
		setCursor(60,15);
		printf("level:  %02d",chosenLevel);

		// Menu options
		while(game == 0) {
			displayScore(displayUpdatePeriod);	// Display score on LEDs 
			if(isLeftKeyPressed()==1 && getTimer0() >= menuKeyDebounce){
				resetTimer0();
				if (chosenLevel > 1) {
					chosenLevel--;
					setCursor(68, 15);
					printf("%02d", chosenLevel);
				}
			}
			if(isRightKeyPressed()==1 && getTimer0() >= menuKeyDebounce){
				resetTimer0();
				if (chosenLevel < NUMBEROFLEVELS) {
					chosenLevel++;
					setCursor(68, 15);
					printf("%02d", chosenLevel);					
				}
			}

			// Start game on enter key press
			if(isEnterKeyPressed()==1 && getTimer0() >= menuKeyDebounce){
				resetTimer0();
				game = 1;
			}
		}

		// Load level from ROM and draw it 
		loadLevelFromROM(levelROM[chosenLevel-1] , level);		
		drawObstructions();

		// Set start position and direction of the ball
		resetPositions(&currentPosition, &nextPosition, &direction);
		health = 3;

		// Game play
		while(game == 1){
			// Striker movement
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

			// Update video buffer
			if(videoBufferUpdate >= 1000){	// Update video buffer approx every second
				insertInVideoBuffer(score);
				videoBufferUpdate = 0;
			}

			displayScore(displayUpdatePeriod);

			// Ball movement
			if (getTimer0() >= ballUpdatePeriodTime) {
				resetTimer0();
				strikerUpdatePeriod = 0;
				displayUpdatePeriod = 0;
				score += ballUpdatePeriodTime;
				drawGameStats(score, health);
				videoBufferUpdate += ballUpdatePeriodTime;	// => updating approx every second

				// Calculate the new position
				calculateNextPosition(&currentPosition,&direction,&nextPosition);	
				updateDirectionOnCollision(&currentPosition,&direction,&nextPosition);

				updateBallOnScreen(&nextPosition);
				currentPosition = nextPosition;
			}
		}
	}
}

/*
	Display the score on the LEDs
*/
void displayScore(short displayUpdatePeriod) {
	char j;
	// Display score
	for (j = 0; j < 5; j++) 
		updateDisplay(j, displayCol, j);
	displayUpdatePeriod++;
	
	if(displayCol == 4)
		displayCol = 0;
	else
		displayCol++;
}

/*
	Set the coordinates of a vector to the parsed arguments 
*/
void setCoordinates(struct Vector *cooridnates, long x, long y) {
	(*cooridnates).x = x << 16;
	(*cooridnates).y = y << 16;
	setCursor(4, 34);
	printf("x: %d, y: %d", x, y);
}

/*
	Reset the striker to the center, and the ball just above going upwards
*/
void resetPositions(struct Vector *currentPosition, struct Vector *nextPosition, struct Vector *direction) {
	// Set start position and direction of the ball
	setCoordinates(currentPosition, WIDTH/2, 0);
	setCoordinates(nextPosition, WIDTH/2, 0);
	setCoordinates(direction, SQRT2HALF, -SQRT2HALF);
	angle = 45; 										// Reset the angle to 45 degrees

	// Reset the striker
	strikerPosition = WIDTH/2;
	drawStriker(strikerWidth, strikerPosition, 0);
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
	Update the ball when it hits something
*/
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
	if (roundToShort(nextPosition->y) == HEIGTH - 2) {
		unsigned short x = roundToShort(nextPosition->x);	// Calculate a rounded value of the x coordinate
		// Check if the ball is inside the striker
		if (x >= strikerPosition - strikerWidth/2 && x <= strikerPosition + strikerWidth/2) {
			direction->y = -direction->y;

			// Change direction vector on right side
			if (x > strikerPosition) {
				if (direction->x > 0) {
					rotate(direction, angle/4);
					angle -= angle/4;
				}
				else{
					if((angle + angle/2) > 90){
						direction->x = -direction->x;
						rotate(direction, -60 + (2*angle)/3);
						angle = angle/2 + 45;
					}
					else{
						rotate(direction, angle/2);
						angle += angle/2;
					}
				}
			} 
			// Change direction vector on left side
			else if (x < strikerPosition) {
				
				if (direction->x > 0) {
					if((angle + angle/2) > 90){
						direction->x = -direction->x;
						rotate(direction, 60 - (2*angle)/3);
						angle = angle/2 + 45;
					}
					else{
						rotate(direction, -angle/2);
						angle += angle/2;
					}
				}
				else{
					rotate(direction, -angle/4);
					angle -= angle/4;
				}
			}
		}

		// Calculate the next position based on the new direction
		calculateNextPosition(position, direction, nextPosition);
	}
	// Check for passing through the lower boundary
	else if (roundToShort(nextPosition->y) > HEIGTH + 2) {
		setCursor(4, 4);
		printf("%d", roundToShort(nextPosition->y));
		if (health > 0) {
			health--;
			resetPositions(position, nextPosition, direction);

			setCursor(40, 33);
			setColor(31, 40);
			printf("You lost a life!");
		} 
		else {
			// Game over
			// clearScreen();
			setColor(36, 40);
			drawBoundaries();
			setCursor(50, 8);
			setColor(31, 40);
			printf("********* GAME OVER! **********");
			game = 0;
		}
		drawGameStats(score, health);
	}
}

/*
	Calculate the collision with the obstructions 
*/
void obstuctionCollision(struct Vector *currentPosition , struct Vector *direction , struct Vector *nextPosition) {
	char neighbourObstruction = 0;
	short x = (unsigned short) (currentPosition->x >> 1);	// 1.15 format
	short y = (unsigned short) (currentPosition->y >> 1);	// 1.15 format
	char arrayPosition = roundToShort(nextPosition->y); 
	char bitPosition = (30 - ((roundToShort(nextPosition->x) >> 3) << 1)); 	// Divide by 8 to get the correct block. Times 2 to get the correct number of bitshifts 
	
	long row = level[arrayPosition];						// Get the row in the level grid

	// check wether or not the next position contains an obstruction
	if(((row >> bitPosition) & 0x3) != 0){

		setCursor(0,1);
		printf("x: %ld     %ld     ", currentPosition->x >> 16 , currentPosition->y >> 16);
		setCursor(0,2);

		// if another obstruction exists on the side, from which the ball is coming, the ball must hit either top or bottom of the obstruction, and hence the y-coordinate is flipped
		if (bitPosition > 2)							// if there is space for a neighbour obstruction on the right side within the game area
			if (((row >> bitPosition-2) & 0x3) !=0)	// check for neighbour obstruction on the right side
				neighbourObstruction |= 0x1;		// set flag

		if (bitPosition < 28)						// if there is space for a neighbour obstruction on the left side within the game area
			if (((row >> bitPosition+2) & 0x3) != 0)	// check for neighbour obstruction on the left side
				neighbourObstruction |= 0x2;		//set flag
		
		if ( ((neighbourObstruction & 0x1) != 0) && (direction->x < 0) )		// if an obstruction exists on the right side and the direction is from right to left
			direction->y = -direction->y;		// flip y-coordinate

		else if ( ((neighbourObstruction & 0x2) != 0) && (direction->x > 0))	// if an obstruction exists on the left side and the direction is from left to right
			direction->y = -direction->y;		// flip y-coordinate


		// if the obstruction has no neighbour obstructions, it must be checked wether or not the ball has collided with the obstruction's side or top/bottom
		else if ( (((30-bitPosition) << 2) <= (currentPosition->x) >> 16) && (((30-bitPosition) << 2)+8 >= (currentPosition->x)>>16) ) {
			direction->y = -direction->y;		// flip y-coordinate
			printf("Top and bottom");		
		}

		else if (arrayPosition == ((currentPosition->y)>>16) + 1) {
			direction->x = - direction->x;		// flip x-coordinate
			printf("Sides");
		}

		
		// DO.MATH
		else if( ((direction->x & (1<<32)) == 1) && ((direction->y & (1<<32)) == 1)) {	// x negative, y negative
			if(x<y) {
				direction->y = -direction->y;
				printf("below right y");
			}
			else {
				direction->x = -direction->x;
				printf("below right x");
			}
		}
		
		else if( ((direction->x & (1<<32)) == 1) && ((direction->y & (1<<32)) == 0)) {	// x negative, y postive
			if(x < (1<<15) - y) {
				direction->y = -direction->y;
				printf("above right y");
			}
			else{
				direction->x = -direction->x;
				printf("above right x");
			}
		}

		else if( ((direction->x & (1<<32)) == 0) && ((direction->y & (1<<32)) == 0)) {	// x postive, y positive
			if(x>y){
				direction->y = -direction->y;
				printf("above left y");
			}
			else {
				direction->x = -direction->x;
				printf("above left x");
			}
		}

		else if( ((direction->x & (1<<32)) == 0) && ((direction->y & (1<<32)) == 1)) {	// x positive, y negative
			if(x > (1<<15) - y) {
				direction->y = -direction->y;
				printf("below left y");
			}
			else {
				direction->x = -direction->x;
				printf("below left x");
			}
		}


	/*	setCursor(20,20);
		printf("long: %ld     ", ((direction->x)<<15)>>15 );
		setCursor(20,21);
		printf("short: %u     ", (unsigned short) direction->x);

		setCursor(20,22);
		printf("%ld", (-4) >> 1);
	*/
		calculateNextPosition(currentPosition, direction, nextPosition);
		updateObstructionOnHit(((row >> bitPosition) & 0x3) , arrayPosition, bitPosition);
	}


	//row = row >> bitPosition;

//	if ((row & 0x3) != 0) {

		//direction->y = -direction->y;

		//calculateNextPosition(currentPosition, direction, nextPosition);

		//updateObstructionOnHit((row & 0x3) , arrayPosition, bitPosition);
//	}
}

/*
	Update a obstuction when it is hit 
*/
void updateObstructionOnHit(char value, char arrayPosition, long bitPosition){
	if(value > 2 || value < 1){
		// solid block, do nothing
	}
	else {
		level[arrayPosition] -= 1 << bitPosition;	// subtract 1 from the value of the hit obstruction's "life"
		drawSingleObstruction(arrayPosition, bitPosition, level[arrayPosition]);
	}
}

/*
	Move data from ROM into RAM
*/
void loadLevelFromROM(long rom *src, long *dest){
	char i;
	for (i=0; i<31; i++){
		*dest++ = *src++;
	}
}