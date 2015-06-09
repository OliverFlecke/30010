// #include "vector.h"
struct TVector {
	long x,y;
};

void initVector(struct TVector *v) {
	v->x = 1;
	v->y = 2;
}

void rotate(struct TVector *v, signed short phi) {
	long temp = v->x * cos(phi) - v->y * sin(phi);
	v->y = v->y * sin(phi) + v->x * cos(phi);
	v->x = temp;
}

void main() {
	struct TVector v;
	initVector(&v);

	printf("%d %d\n", v.x, v.y);

	rotate(&v, 180);
}