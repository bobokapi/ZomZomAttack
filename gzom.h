/*
This is the definition of the GZom class. This class defines the behavior of the giant ZomZom objects in the game. It inherits from ZomZom.
*/
#ifndef GZOM_H
#define GZOM_H

#include "zomzom.h"
using namespace std;

class GZom : public ZomZom {
  public:
	GZom(): ZomZom(2,30) {
		Object::dpoints = 62684;
		Object::dhealth = -50;
		
		image.load("gzom.png");
		rect = image.rect();
		resetState();
	}
	
	// also reset health
	void resetState() {
		Object::resetState();
		ZomZom::health = 30;
	}
};

#endif
