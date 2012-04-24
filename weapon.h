/*
This is the definition of the Weapon class. This class defines the behavior of the weapon objects in the game. It inherits from Object.
*/
#ifndef WEAPON_H
#define WEAPON_H

#include "object.h"
using namespace std;

class Weapon : public Object {
  public:
	Weapon(): Object(0) {
		Object::dpoints = 11111;
		Object::dhealth = 0;
		
		image.load("weapon.png");
		rect = image.rect();
		resetState();
	}
	
	/* This method changes the Object collision method to also reset position and direction. */
	virtual void collision(int& points, int& health) {
		Object::collision(points, health);
		resetState();
	}
};

#endif
