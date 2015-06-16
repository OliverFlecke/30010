#ifndef SERIAL_H
#define SERIAL_H

// Libraries
#include <sio.h>

// constants
#define ESC 27

// Size of the game
#define height 32
#define width 128

// Functions
void clearScreen();
void clearLine();
void initSerial();

void setCursor(short x, short y);
void setColor(short fg, short bg);

// Draw game element functions
void drawBoundaries();
void drawStriker(char strikerWidth, unsigned char strikerPosition, char direction);
void updateBallOnScreen(struct Vector *currentPostion , struct Vector *nextPostion);


//void drawBall(short x, short y);
void drawBlankSpace(short x, short y);

void initSerial();
void homeCursor();

#endif