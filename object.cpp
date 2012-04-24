/*
This is the definition of the Object class. This class defines the behavior of the objects in the game: small Zomzom, adult Zomzom, giant Zomzom, weapons, and mysterious constructions.
*/
#include "object.h"
#include <stdlib.h> // for rand

using namespace std;

/* This constructor is only ever called by the constructors of it's child classes. The constructor takes a value for the speed of the Object in order to know whether to initialize direction. It also calls the Object's resetState() function. */
Object::Object(int speed) {
	this->speed = speed;
	this->resetState();
}

/* This method moves the Object based on the Object's speed and checks to see if the Object has hit a boundary and must bounce. It is virtual so that it can be redefined by child classes. */
void Object::autoMove(int px, int py) {
	for (int i = 0; i < speed; i++) {
		rect.translate(dx, dy);

		if (rect.left() == 0) {
			dx = 1;
		}
		if (rect.right() == 500) {
			dx = -1;
		}
		if (rect.top() == 0) {
			dy = 1;
		}
		if (rect.bottom() == 400) {
			dy = -1;
		}
	}
}

/* This method randomizes the location and direction of the Object. It is virtual so that it can be redefined by child classes. */
void Object::resetState() {
	int x = rand() % 500;
	int y = rand() % 400;
	rect.moveRight(x);
	rect.moveBottom(y);
	
	if (speed != 0) {
		int dir = rand() % 8;
		if (dir == 0 || dir == 3 || dir == 5) dy = -1;
		if (dir == 2 || dir == 4 || dir == 7) dy = 1;
		if (dir < 3) dx = -1;
		if (dir > 4) dx = 1;
	}
}

/* These methods move the object. */
void Object::moveBottom(int bottom) {
	rect.moveBottom(bottom);
}
void Object::moveTop(int top) {
	rect.moveTop(top);
}
void Object::moveLeft(int left) {
	rect.moveLeft(left);
}
void Object::moveRight(int right) {
	rect.moveRight(right);
}

/* These methods set the Object's direction. */
void Object::setXDir(int x) {
	dx = x;
}
void Object::setYDir(int y) {
	dy = y;
}

/* Getters */
int Object::getXDir() {
	return dx;
}
int Object::getYDir() {
	return dy;
}
QRect Object::getRect() {
	return rect;
}
QImage & Object::getImage() {
	return image;
}

/* This method is called when the Object is colliding with the player, and it changes the player's points and health accordingly. It is virtual so that it can be redefined by child classes. */
void Object::collision(int& points, int& health) {
	points += Object::dpoints;
	if (points < 0) points = 0; // prevents negative points
	health += Object::dhealth;
}

/* This method awards points and resets the Object. */
void Object::bulletCollision(int& points) {
	points += Object::dpoints;
	if (points < 0) points = 0; // prevents negative points
}
