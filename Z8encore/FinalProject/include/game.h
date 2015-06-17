#ifndef GAME_H
#define GAME_H

// Libraries
#include "vector.h"	
#include "numberformat.h"
#include "timer.h"
#include "serialDriver.h"
#include "keyDriver.h"
#include "trigonometry.h"

// Constants
#define HEIGTH 32
#define WIDTH 128

// Functions
void calculateNextPosition(struct Vector *postition , struct Vector *direction , struct Vector *nextPosition);
void drawObstructions();
void obstuctionCollision(struct Vector *position , struct Vector *direction , struct Vector *nextPosition);
void updateDirectionOnCollision(struct Vector *postition , struct Vector *direction , struct Vector *nextPosition);
void updateObstructionOnHit(char value, char arrayPosition, long bitPosition);
void mainGame();

#endif