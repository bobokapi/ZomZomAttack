/*
This is the definition of the MCon class. This class defines the behavior of the mysterious construction objects in the game. It inherits from Object.
*/
#ifndef MCON_H
#define MCON_H

#include "object.h"
using namespace std;

class MCon : public Object {
  private:
	/* This method randomly initializes the attributes of a mysterious construction. It is called when the Object is created and when it collides with the player. */
	virtual void mysterious() {
		Object::dpoints = rand() % 60001 - 30000; // (-30000 to 30000)
		Object::dhealth = rand() % 5 * 10; // (0 to 50)
	}
	
  public:
	MCon(): Object(2) {
		Object::dpoints = 3;
		Object::dhealth = 0;
		
		image.load("mcon.png");
		rect = image.rect();
		resetState();
	}
	
	/* This method changes the Object collision method to also reset position and direction. */
	virtual void collision(int& points, int& health) {
		Object::collision(points, health);
		resetState();
		mysterious();
	}
};

#endif
