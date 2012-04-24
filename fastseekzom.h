/*
This is the definition of the FastSeekZom class. This class defines the behavior of the fast seeker ZomZom objects in the game. It inherits from ZomZom.
*/
#ifndef FASTSEEKZOM_H
#define FASTSEEKZOM_H

#include "zomzom.h"
#include <cmath>
using namespace std;

class FastSeekZom : public ZomZom {
  public:
	FastSeekZom(): ZomZom(2,20) {
		Object::dpoints = 178060;
		Object::dhealth = -30;
		
		image.load("seekzom.png");
		rect = image.rect();
		resetState();
	}
	
	// also reset health
	void resetState() {
		Object::resetState();
		ZomZom::health = 20;
	}
	
	/* This overwrites the default automove so that the seeker zombie will try to move directly towards the character. */
	virtual void autoMove(int px, int py) {
		double dxtmp, dytmp, length;
		dxtmp = (double)(px - rect.center().rx());
		dytmp = (double)(py - rect.center().ry());
		
		length = sqrt(dxtmp * dxtmp + dytmp * dytmp);
		dxtmp /= length / 2;
		dytmp /= length / 2;
		dx = (int)(dxtmp + 0.5);
		dy = (int)(dytmp + 0.5);
		
		for (int i = 0; i < speed; i++) rect.translate(dx, dy);
	}
};

#endif
