#ifndef TRIG_H
#define TRIG_H

// === LUT SIZES ===
#define SIN_SIZE 512

// === LUT DECLARATIONS ===
extern const signed short SIN[512];

// Functions to get sinus and cosine
signed long sin(signed long x);
signed long cos(signed long x);

#endif
