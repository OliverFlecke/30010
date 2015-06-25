#include "vector.h"

/*
	Rotates a vetor by the passed angle 
*/
void rotate(struct Vector *v, signed short phi) {
	long temp;
	
	temp = ((v->x) >> 2) * (cos(phi) >> 2) - ((v->y) >> 2) * (sin(phi) >> 2);
	v->y = (((v->x) >> 2) * (sin(phi) >> 2) + ((v->y) >> 2) * (cos(phi) >> 2)) >> 12;
	v->x = temp >> 12;
}