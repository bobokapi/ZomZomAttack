/*
This is the definition of the SZom class. This class defines the behavior of the small ZomZom objects in the game. It inherits from ZomZom.
*/
#ifndef SZOM_H
#define SZOM_H

#include "zomzom.h"
using namespace std;

class SZom : public ZomZom {
  public:
	SZom(): ZomZom(5,10) {
		Object::dpoints = 25234;
		Object::dhealth = 0;
		
		image.load("szom.png");
		rect = image.rect();
		resetState();
	}
	
	// also reset health
	void resetState() {
		Object::resetState();
		ZomZom::health = 10;
	}
};

#endif
