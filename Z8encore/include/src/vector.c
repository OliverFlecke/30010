#include "vector.h"
#include <sio.h>
#include "lut.h"
#include "numberformat.h"

void initVector(struct TVector *v) {
	v->x = 6;
	v->y = 4;
}


/*
	Rotates a vetor by the passed angle 
*/
void rotate(struct TVector *v, signed short phi) {
	long temp = convert1814(v->x) * cos(phi) - convert1814(v->y) * sin(phi);
	v->y = (convert1814(v->x) * sin(phi) + convert1814(v->y) * cos(phi)) >> 14;
	v->x = temp >> 14;
}


