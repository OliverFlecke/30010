#ifndef LEVEL_H
#define LEVEL_H

#define NUMBEROFLEVELS 10

// Functions
void loadLevelFromROM(long rom *src, long *dest);

extern rom long levelROM[][32];

#endif