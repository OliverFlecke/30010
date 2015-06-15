#include "vector.h"


void initVector(struct Vector *v) {
	v->x = 1 << 16;
	v->y = 1 << 16;
}


/*
	Rotates a vetor by the passed angle 
*/
void rotate(struct Vector *v, signed short phi) {
	long temp = (v->x) * cos(phi) - (v->y) * sin(phi);
	v->y = ((v->x) * sin(phi) + (v->y) * cos(phi));
	v->x = temp;
}


