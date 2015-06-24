#include "game.h"

unsigned short strikerPosition;
char strikerWidth = 11;		// Must be an odd number
short angle;			// Start angle. Must match start direction vector
unsigned long score = 0;
unsigned char health;
char displayCol = 0;
char game = 0;
char chosenLevel = 1;
long level[32];
long obstructionsRemaining;
const long SQRT2HALF = 0xB504;

/*
	The main game loop. Handles manu and keeps track of user input on a high level
*/
void mainGame() {
	// Game variables 
	const unsigned char menuKeyDebounce = 150;	// Delay to avoid keybounce 
	short ballUpdatePeriodTime = 30;			// Speed of the ball
	short strikerUpdatePeriod = 10;				// Speed of the striker
	short displayUpdatePeriod = 1;				// Refresh rate of the LEDs	
	short videoBufferUpdate = 1000;				// Refresh rate of the videobuffer

	// initialize vectors
	struct Vector direction;					// Direction of the ball
	struct Vector currentPosition;				// The current position of the ball
	struct Vector nextPosition;					// The next position of the ball

	// Clears the screen and draws the boundaries 
	clearScreen();
	drawBoundaries();

	// Init keys
	initKeys();		// Register the keys as input
	initTimer0();	// Setup timer 0

	// Game loop - Ingame and menu
	while (1 == 1) {
		// Print out menu
		setCursor(60,12);
		setColor(blueTextColor, backgroundColor);
		printf("START GAME");
		setCursor(60,15);
		printf("Level:  %02d", chosenLevel);

		// Display user guide
		setCursor(50, 20);
		printf("Left button   -   Lower level");
		setCursor(50, 21);
		printf("Right button  -   Higher level");
		setCursor(50, 22);
		printf("Center button -   Start game");

		// Menu options
		while (game == 0) {
			displayScore(displayUpdatePeriod);	// Display score on LEDs 

			// Change level if left key is pressed
			if (isLeftKeyPressed() == 1 && getTimer0() >= menuKeyDebounce) {
				resetTimer0();
				if (chosenLevel > 1) {		// Insure we chose a level that exists 
					chosenLevel--;
					setCursor(68, 15);		
					printf("%02d", chosenLevel); 	// Update the displayed level
				}
			}
			// Increment selected level on right key press
			if (isRightKeyPressed() == 1 && getTimer0() >= menuKeyDebounce) {
				resetTimer0();
				if (chosenLevel < NUMBEROFLEVELS) {	// Insure wer chose a level that exists
					chosenLevel++;
					setCursor(68, 15);
					printf("%02d", chosenLevel);	// Update displayed level
				}
			}

			// Start game on enter key press
			if(isEnterKeyPressed()==1 && getTimer0() >= menuKeyDebounce){
				resetTimer0();
				game = 1;	// Set the game flag
			}
		}

		// Load level from ROM and draw it 
		loadLevelFromROM(levelROM[chosenLevel-1] , level);		
		drawObstructions();		// Draw obstruction from the loaded level map
		drawStriker(strikerWidth, strikerPosition, 0);
		// Set start position and direction of the ball
		resetPositions(&currentPosition, &nextPosition, &direction);

		// Sets the health and displays it to the user
		health = 3;
		drawGameStats(health, obstructionsRemaining);

		// Game loop
		while (game == 1) {
			displayScore(displayUpdatePeriod);

			// Striker movement
			if (getTimer0() >= strikerUpdatePeriod) {
				strikerUpdatePeriod += 25;
				// Move striker left, when the left key is pressed
				if (isLeftKeyPressed() == 1 && strikerPosition > strikerWidth/2) {
					drawStriker(strikerWidth, strikerPosition, -1);
					strikerPosition--;
				} 
				// Move the striker right, if the right key is pressed 
				if (isRightKeyPressed() == 1 && strikerPosition < WIDTH - 1 - strikerWidth/2) {
					drawStriker(strikerWidth, strikerPosition, 1); 	
					strikerPosition++;
				}
			}

			// Update video buffer with the current score 
			if (videoBufferUpdate >= 1000) {	// Update video buffer approx every second
				insertInVideoBuffer(score);		// Update the video buffer
				videoBufferUpdate = 0;			// Reset the update counter
			}

			

			// Ball movement
			if (getTimer0() >= ballUpdatePeriodTime) {
				resetTimer0();				// Reset the timer
				strikerUpdatePeriod = 0;	// Reset the update time for striker
				displayUpdatePeriod = 0;	// Reset the update time for display
				score += ballUpdatePeriodTime;	// Increment score
				videoBufferUpdate += ballUpdatePeriodTime;	// => updating approx every second

				// Calculate the new position and update the direction
				calculateNextPosition(&currentPosition, &direction, &nextPosition);	
				updateDirectionOnCollision(&currentPosition, &direction, &nextPosition);

				// Update the ball on the screen 
				updateBallOnScreen(&nextPosition);
				currentPosition = nextPosition;	
			}
		}
	}
}

/*
	Calculate the position for the ball in the next time step
*/
void calculateNextPosition(struct Vector *position , struct Vector *direction , struct Vector *nextPosition){
	nextPosition->x = position->x + direction->x;	
	nextPosition->y = position->y + ((direction->y) >> 1);	// times 1/2 for correction of the uneven pixel density of the console
}

/*
	Display the score on the microcontroller's LEDs
	The function updates the colomn saved in displayCol on each display
*/
void displayScore(short displayUpdatePeriod) {
	char j;
	// Display score
	for (j = 0; j <= 4; j++) // Loop through each display 
		updateDisplay(j, displayCol, j);
	displayUpdatePeriod++;
	
	// Updates the colomn to the next 
	if (displayCol == 4)	// When the last column is select, reset
		displayCol = 0;
	else
		displayCol++;
}

/*
	Set the coordinates of a vector to the parsed arguments 
	Insures the coordinates is saved in 16.16 format
*/
void setCoordinates(struct Vector *cooridnates, long x, long y) {
	(*cooridnates).x = x << 16;
	(*cooridnates).y = y << 16;
}

/*
	Reset the striker to the center, and the ball just above going upwards
*/
void resetPositions(struct Vector *currentPosition, struct Vector *nextPosition, struct Vector *direction) {
	// Set start position and direction of the ball
	setCoordinates(currentPosition, WIDTH/2, 28);
	// Direction set to match a 45 degree angle
	// The direction vector should always have a lenght as close as possible to 1
	direction->x = SQRT2HALF;
	direction->y = -SQRT2HALF;
	angle = 45; 										// Reset the angle to 45 degrees
	calculateNextPosition(currentPosition, direction, nextPosition);

	// Reset the striker
	strikerPosition = WIDTH/2;
	drawStriker(strikerWidth, strikerPosition, 0);
}


/*
	Draw game obstruction on the game grid
*/
void drawObstructions() {
	char i, j;
	for (i = 0; i < HEIGTH; i++) // Loop through each row
		for (j = 30; j >= 0; j -= 2) // Loop through each column
			// Draw the current obstruction
			obstructionsRemaining += drawSingleObstruction(i, j, level[i]);	
}


/*
	Update the ball when it hits something. 
	This takes into account the walls, striker, and calls an obstructions collsion function
*/
void updateDirectionOnCollision(struct Vector *position , struct Vector *direction, struct Vector *nextPosition) {
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

	// Check for collision with the striker
	if (roundToShort(nextPosition->y) == HEIGTH - 2) {
		unsigned short x = roundToShort(nextPosition->x);	// Calculate a rounded value of the x coordinate
		// Check if the ball is inside the striker
		if (x >= strikerPosition - strikerWidth/2 && x <= strikerPosition + strikerWidth/2) {
			direction->y = -direction->y;

			// Update the angle of the balls direction, based on were it hit
			// Each zone is calculated to match a change in angle, that works well ingame
			// Change direction vector on right side furthest from the center
			if (x > strikerPosition + strikerWidth/4 && x <= strikerPosition + strikerWidth/2) {
				if (direction->x > 0) {
					rotate(direction, angle/4);
					angle -= angle/4;
				}
				else {
					if ((angle + angle/2) > 90) {
						direction->x = -direction->x;
						rotate(direction, -60 + (2*angle)/3);
						angle = angle/2 + 45;
					}
					else {
						rotate(direction, angle/2);
						angle += angle/2;
					}
				}
			} 
			// Change direction vector when the ball hits the right side closest to the center
			else if (x > strikerPosition && x <= strikerPosition + strikerWidth/4) {
				if (direction->x > 0) {
					rotate(direction, angle/6);
					angle -= angle/6;
				}
				else {
					if ((angle + angle/3) > 90) {
						direction->x = -direction->x;
						rotate(direction, -120 + (4*angle)/3);
						angle = angle/3 + 60;
					}
					else {
						rotate(direction, angle/3);
						angle += angle/3;
					}
				}
			}

			// Change direction vector when the ball hits the left side closest to the center
			else if (x < strikerPosition && x >= strikerPosition - strikerWidth/4) {
				if (direction->x > 0) {
					if((angle + angle/3) > 90) {
						direction->x = -direction->x;
						rotate(direction, 120 - (4*angle)/3);
						angle = angle/3 + 60;
					}
					else {
						rotate(direction, -angle/3);
						angle += angle/3;
					}
				}
				else {
					rotate(direction, -angle/6);
					angle -= angle/6;
				}
			}
			// Change direction vector on left side furthest from the center
			else if (x < strikerPosition - strikerWidth/4 && x >= strikerPosition - strikerWidth/2) {
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
	// Check for passing through the lower boundary ann thereby the player died
	else if (roundToShort(nextPosition->y) > HEIGTH - 2) {
		// If the player stil has any health left, he loses a life and the game contiues
		if (health > 0) {
			health--;
			resetPositions(position, nextPosition, direction);
			drawGameStats(health, obstructionsRemaining);

			// Tell the player he has lost a life
			setCursor(58, 33);
			printf("You lost a life!");
			resetTimer0();
			while (getTimer0() <= 2000) { /* wait two seconds */ }
			setCursor(58, 33);		
			printf("                 "); // remove the text again	
		} 
		else {
			// Game over
			clearScreen();
			drawBoundaries();
			setCursor(50, 8);
			setColor(redTextColor, backgroundColor);
			printf("********* GAME OVER! **********");
			game = 0;
		}
	}
}

/*
	Update a obstuction when it is hit 
*/
void updateObstructionOnHit(char value, char arrayPosition, long bitPosition) {
	// If the obstruction is an obstuction with life, we change it 
	if (value <= 2 && value >= 1) {
		level[arrayPosition] -= 1 << bitPosition;	// subtract 1 from the value of the hit obstruction's "life"
		drawSingleObstruction(arrayPosition, bitPosition, level[arrayPosition]);	// Update displayed obstruction
		obstructionsRemaining--;						// Substract 1 from the remaining obstruction
		drawGameStats(health, obstructionsRemaining);	// Update the displayed game stats

		// If there is no obstructions remaning, the player wins 
		if (obstructionsRemaining <= 0) {
			clearScreen();		
			drawBoundaries();

			// Display winning text
			setCursor(54, 6);
			setColor(greenTextColor, backgroundColor);
			printf("****** YOU WON! *******");
			setCursor(48, 8);
			printf("Press enter to start the next level");
			game = 0;		// Set game flag to end
			chosenLevel++;	// Increment the selected level
		}
	}
}

/*
	Calculate the collision with the obstructions 
*/
void obstuctionCollision(struct Vector *currentPosition , struct Vector *direction , struct Vector *nextPosition) {
	char arrayPosition = roundToShort(nextPosition->y); 		// Get the position of the obstruction in the array
	char bitPosition = (30 - ((roundToShort(nextPosition->x) >> 3) << 1)); 	// Divide by 8 to get the correct block. Times 2 to get the correct number of bitshifts 
	
	long row = level[arrayPosition];						// Get the row in the level grid

	// check wether or not the next position contains an obstruction
	if (((row >> bitPosition) & 0x3) != 0){
		// Check if the next position is in one of the end pixels of the obstruction
		if (roundToShort(nextPosition->x) % 8 == 0) {
			if (roundToShort(currentPosition->x) % 8 == 7 
				&& roundToShort(currentPosition->y) == roundToShort(nextPosition->y))
				direction->x = -direction->x;
			else 
				direction->y = -direction->y;
		} 
		else if (roundToShort(nextPosition->x) % 8 == 7) {
			if (roundToShort(currentPosition->x) % 8 == 0 
				&& roundToShort(currentPosition->y) == roundToShort(nextPosition->y))
				direction->x = -direction->x;
			else 
				direction->y = -direction->y;
		}
		// If not, just flip the y direction
		else 
			direction->y = -direction->y;

		// Update the next position and the obstruction that got hit
		calculateNextPosition(currentPosition, direction, nextPosition);
		updateObstructionOnHit(((row >> bitPosition) & 0x3) , arrayPosition, bitPosition);
	}
}