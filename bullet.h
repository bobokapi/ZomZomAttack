/*
This is the definition of the Bullet class. This class defines the behavior of the bullet objects in the game. It inherits from Object.
*/
#ifndef BULLET_H
#define BULLET_H

#include "object.h"
#include <cmath>
using namespace std;

class Bullet : public Object {
  public:
	/* This constructor takes two points, the origin of the bullet and the target, assigns the origin to the bullet's location, and then calculates the change in x and y based on the speed of the bullet. */
	Bullet(QPoint origin, QPoint target): Object(10) {
		image.load("bullet.png");
		rect = image.rect();
		
		Object::dpoints = 0;
		Object::dhealth = -10;
		rect.moveLeft(origin.rx());
		rect.moveTop(origin.ry());
		
		double dxtmp, dytmp, length;
		dxtmp = (double)(target.rx() - origin.rx());
		dytmp = (double)(target.ry() - origin.ry());
		
		length = sqrt(dxtmp * dxtmp + dytmp * dytmp);
		dxtmp /= length / 5;
		dytmp /= length / 5;
		dx = (int)(dxtmp + 0.5);
		dy = (int)(dytmp + 0.5);
	}
	
	/* This overwrites the default automove so that the bullet will move correctly in one direction. */
	virtual void autoMove(int px, int py) {
		for (int i = 0; i < speed / 5; i++) rect.translate(dx, dy);
	}
	
	/* This method determines whether or not the bullet is done firing (offscreen) */
	bool isDone() {
		return (rect.left() < 1 ||
				rect.right() > 499 ||
				rect.top() < 1 ||
				rect.bottom() > 399);
	}
};

#endif
