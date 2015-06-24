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

// Functions
void mainGame();

void calculateNextPosition(struct Vector *postition , struct Vector *direction , struct Vector *nextPosition);
void displayScore(short displayUpdatePeriod);
void setCoordinates(struct Vector *ballPosition, long x, long y);
void resetPositions(struct Vector *currentPosition, struct Vector *nextPosition, struct Vector *direction);

// Obstruction relevent function
void drawObstructions();
void updateDirectionOnCollision(struct Vector *postition , struct Vector *direction , struct Vector *nextPosition);
void updateObstructionOnHit(char value, char arrayPosition, long bitPosition);
void obstuctionCollision(struct Vector *position , struct Vector *direction , struct Vector *nextPosition);

#endif