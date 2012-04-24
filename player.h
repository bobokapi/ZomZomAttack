/*
This is the definition of the Player class. This class defines the behavior of the player's avatar in the game.
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <QImage>
#include <QRect>

class Player
{
  private:
	QImage image;
	QRect rect;
	
  public:
	Player();
	void resetState();
	void moveLeft(int);
	void moveRight(int);
	void moveTop(int);
	void moveBottom(int);
	QRect getRect();
	QImage & getImage();
};

#endif
