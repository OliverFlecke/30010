#ifndef GAME_H
#define GAME_H

// Libraries
#include "vector.h"	
#include "numberformat.h"
#include "timer.h"
#include "serialDriver.h"
#include "keyDriver.h"
#include "trigonometry.h"
#include "displayDriver.h"
#include "level.h"

// Constants
#define HEIGTH 32
#define WIDTH 128
const long SQRT2HALF = 0xB504;

// Functions
void calculateNextPosition(struct Vector *postition , struct Vector *direction , struct Vector *nextPosition);
void drawObstructions();
void obstuctionCollision(struct Vector *position , struct Vector *direction , struct Vector *nextPosition);
void updateDirectionOnCollision(struct Vector *postition , struct Vector *direction , struct Vector *nextPosition);
void updateObstructionOnHit(char value, char arrayPosition, long bitPosition);
void loadLevelFromROM(long rom *src, long *dest);
void mainGame();
void displayScore(short displayUpdatePeriod);
void setCoordinates(struct Vector *ballPosition, long x, long y);
void resetPositions(struct Vector *currentPosition, struct Vector *nextPosition, struct Vector *direction);


#endif