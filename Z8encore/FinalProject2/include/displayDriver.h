#ifndef DISPLAY_H
#define DISPLAY_H

#include <eZ8.h>
#include <sio.h>
#include "charset.h"
#include "serialDriver.h"

void showBinaryDisplay0(char i);
void clockDisplay0();
void clockDisplay1();
void clockDisplay2();
void clockDisplay3();
void clockDisplays();

void clockDisplay(char display);
void updateDisplay(char character, char col, char display);
void insertInVideoBuffer(long value);

#endif