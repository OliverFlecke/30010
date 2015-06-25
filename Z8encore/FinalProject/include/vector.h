#ifndef VECTOR_H
#define VECTOR_H

// Define a vector struct
struct Vector {
	long x,y;
};

// Libraries
#include "trigonometry.h"
#include "numberformat.h"

// Functions 
void rotate(struct Vector *v, signed short phi);

#endif