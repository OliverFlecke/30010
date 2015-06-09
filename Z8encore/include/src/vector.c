#include "vector.h"
#include <sio.h>
#include "lut.h"
#include "numberformat.h"

struct TVector {
	long x,y;
};

void initVector(struct TVector *v) {
	v->x = 1;
	v->y = 2;
}

long convert1814(long i) {
	return i << 16;
}

void rotate(struct TVector *v, signed short phi) {
	long temp = convert1814(v->x) * cos(phi) - convert1814(v->y) * sin(phi);
	v->y = convert1814(v->y) * sin(phi) + convert1814(v->x) * cos(phi);
	v->x = temp;
}

void main() {
	struct TVector v;
	initVector(&v);

	printf("%d %d\n", v.x, v.y);

	// printf("%d %d\n", cos(180), sin(180));
	// printFixedPoint1616(convert1616(cos(180)));
	rotate(&v, 180);
}