#ifndef DISPLAY_H
#define DISPLAY_H

// Libraries
#include <eZ8.h>
#include <sio.h>
#include "charset.h"
#include "serialDriver.h"

// Functions 
void clockDisplay0();
void clockDisplay1();
void clockDisplay2();
void clockDisplay3();

void clockDisplay(char display);
void updateDisplay(char character, char col, char display);
void insertInVideoBuffer(long value);

#endif