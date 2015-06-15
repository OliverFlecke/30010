#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
	long x,y;
};

#include "trigonometry.h"
#include "numberformat.h"

void initVector(struct Vector *v);
void rotate(struct Vector *v, signed short phi);

#endif