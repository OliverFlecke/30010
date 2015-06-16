#ifndef GAME_H
#define GAME_H

// Libraries
#include "vector.h"	
#include "numberformat.h"
#include "Timer.h"
#include "SerialDriver.h"
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
void mainGame();

#endif