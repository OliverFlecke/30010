#ifndef KEY_H
#define KEY_H

// Libraries
#include <eZ8.h>
#include "timerDriver.h"

// Functions
void initKeyPF6();
void initKeyPD3();
void initKeyPF7();
void initKeys();

// Check keypresses functions
char isLeftKeyPressed();
char isRightKeyPressed();
char isEnterKeyPressed();

#endif