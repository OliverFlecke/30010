#include <eZ8.h>   // special encore constants, macros and flash functions
#include <sio.h>	 // special encore serial i/o functions
#include "vector.h"


void calculateNextPosition(struct Vector *postition , struct Vector *direction , struct Vector *nextPosition){
	nextPosition->x = postition->x + direction->x;
	nextPosition->y = postition->y + direction->y;
}


main(){
	// initialize vectors
	struct Vector direction;
	struct Vector currentPosition;
	struct Vector nextPosition;
	initVector(&direction);
	initVector(&currentPosition);
	initVector(&nextPosition);

	int i;
	for(i=0; i<20; i++){
		updateBallOnScreen(currentPosition,nextPosition);
		currentPosition = nextPosition;
	}

}












/*void calculateDirectionRelations(struct Vector *direction , struct Vector *directionRelation1 , struct Vector *directionRelation2){
	// calculate direction relation of first order
	if(direction->x == direction->y){
		directionRelation1->x = 1;
		directionRelation1->y = 1;
	}
	else if(direction->x > direction->y){
		directionRelation1->x = direction->x / direction->y;
		directionRelation1->y = 1;
	}
	else
		directionRelation1->x = 1;
		directionRelation1->y = direction->y / direction->x;
	}

	// calculate direction relation of second order
	if(direction->x == direction->y){
		directionRelation2->x = 0;
		directionRelation2->y = 0;
	}
	else if(direction->x > direction->y){
		directionRelation1->x = direction->x / direction->y;
		directionRelation1->y = 1;
	}
	else
		directionRelation1->x = 1;
		directionRelation1->y = direction->y / direction->x;
	}	
}
*/
