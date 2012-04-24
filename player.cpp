#include "player.h"
#include <iostream>

/* The constructor creates a player by assigning the image and rectangle and initializing position. */
Player::Player() {
	image.load("player.png");

	rect = image.rect();
	resetState();
}

/* These methods move the player in one direction as long as the player is not next to a boundary. */
void Player::moveLeft(int left) {
	if (rect.left() > 0)
		rect.moveTo(left, rect.top());
}
void Player::moveRight(int right) {
	if (rect.right() < 500)
		rect.moveTo(right, rect.top());
}
void Player::moveTop(int top) {
	if (rect.top() > 0)
		rect.moveTo(rect.left(), top);
}
void Player::moveBottom(int bottom) {
	if (rect.bottom() < 400)
		rect.moveTo(rect.left(), bottom);
}

/* This method moves the player to the center of the screen. */
void Player::resetState() {
	rect.moveTo(250 - rect.width() / 2, 200 - rect.height() / 2);
}

/* Getters */
QRect Player::getRect() {
	return rect;
}
QImage & Player::getImage() {
	return image;
}
