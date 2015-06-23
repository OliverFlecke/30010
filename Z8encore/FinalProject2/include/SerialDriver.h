#ifndef SERIAL_H
#define SERIAL_H

// Libraries
#include <sio.h>

// constants
#define ESC 27

// Size of the game
#define height 32
#define width 128

// Colors
#define solidColor 36
#define block2LifeColor 32
#define block1LifeColor 31
#define strikerColor 35
#define ballColor 37
#define backgroundColor 40
#define redTextColor 31

// Functions
void clearScreen();
void clearLine();
void initSerial();
void homeCursor();


void setCursor(short x, short y);
void setColor(short fg, short bg);

// Draw game element functions
void drawBoundaries();
void drawStriker(char strikerWidth, unsigned char strikerPosition, char direction);
void updateBallOnScreen(struct Vector *nextPostion);

char drawSingleObstruction(char arrayPosition, long bitPosition, long current);

void drawBlankSpace(short x, short y);

void drawGameStats(unsigned char health, unsigned long obstructions);

#endif