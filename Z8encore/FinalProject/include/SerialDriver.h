#ifndef SERIAL_H
#define SERIAL_H

// Libraries
#include <sio.h>

// constants
#define ESC 27

// Size of the game
#define height 32
#define width 128

// Define colors to display in the console 
#define solidColor 36
#define block2LifeColor 32
#define block1LifeColor 31
#define strikerColor 35
#define ballColor 37
#define backgroundColor 40
#define redTextColor 31
#define blueTextColor 36
#define greenTextColor 32

// Functions
void clearScreen();
void clearLine();
void setCursor(short x, short y);
void setColor(short fg, short bg);
void initSerial();
void homeCursor();

// Draw game element functions
void drawBoundaries();
void drawStriker(char strikerWidth, unsigned char strikerPosition, char direction);
void drawBlankSpace(short x, short y);

void updateBallOnScreen(struct Vector *nextPostion);
char drawSingleObstruction(char arrayPosition, long bitPosition, long current);
void drawGameStats(unsigned char health, unsigned long obstructions);

#endif