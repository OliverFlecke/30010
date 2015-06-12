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
void drawStriker(char direction);
void drawBall(short x, short y);
void drawBlankSpace(short x, short y);


#endif