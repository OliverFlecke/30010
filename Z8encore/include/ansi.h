#ifndef _ANSI_H_
#define _ANSI_H_

// libraries
#include <sio.h>	 // special encore serial i/o functions
#include <string.h>


// constants
#define ESC 27

// functions
void clearScreen();
void clearLine();
void setCursor(int x, int y);
void underline(char on);
void blink(char on);
void reverseBackground();
void window(int x1, int y1, int x2, int y2, char str[], int size, char style);
void printEscapeChar(char a);
void setColor(short fg, short bg);

#endif