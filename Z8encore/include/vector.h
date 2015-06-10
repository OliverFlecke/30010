#ifndef TVECTOR_H
#define TVECTOR_H

struct TVector {
	long x,y;
};

void initVector(struct TVector *v);
void rotate(struct TVector *v, signed short phi);

#endif