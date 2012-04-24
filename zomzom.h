/*
This is the definition of the ZomZom class. This is the base class for ZomZom objects in the game. It inherits from Object.
*/
#ifndef ZOMZOM_H
#define ZOMZOM_H

#include "object.h"
#include <iostream>
using namespace std;

class ZomZom : public Object {
  protected:
	int health;
	
  public:
	ZomZom(int speed, int health): Object(speed) {
		this->health = health;
	}
	
	/* This method changes the Object collision method to subtract health form the ZomZom, and deals with ZomZom death by changing the player's points and resetting the ZomZom. */
	virtual void collision(int& points, int& pHealth) {
		this->health -= 10;
		if (health < 1) {
			points += dpoints;
			resetState();
		} else {
			Object::resetState();
		}
		pHealth += Object::dhealth;
	}
	
	/* This method damages the ZomZom and if it is killed, awards points and resets it. */
	virtual void bulletCollision(int& points) {
		this->health -= 10;
		if (health < 1) {
			points += dpoints;
			resetState();
		}
	}
};

#endif
