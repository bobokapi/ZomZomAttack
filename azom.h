/*
This is the definition of the AZom class. This class defines the behavior of the adult ZomZom objects in the game. It inherits from ZomZom.
*/
#ifndef AZOM_H
#define AZOM_H

#include "zomzom.h"
using namespace std;

class AZom : public ZomZom {
  public:
	AZom(): ZomZom(3,20) {
		Object::dpoints = 38945;
		Object::dhealth = -30;
		
		image.load("azom.png");
		rect = image.rect();
		resetState();
	}
	
	// also reset health
	void resetState() {
		Object::resetState();
		ZomZom::health = 20;
	}
};

#endif
