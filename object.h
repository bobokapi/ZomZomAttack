/*
This is the definition of the Object class. This class defines the behavior of the objects in the game: small Zomzom, adult Zomzom, giant Zomzom, weapons, and mysterious constructions.
*/
#ifndef OBJECT_H
#define OBJECT_H

#include <QImage>
#include <QRect>

class Object
{
  protected:
	int speed;
	int dx;
	int dy;
	int dpoints;
	int dhealth;
	QImage image;
	QRect rect;    

  public:
	Object(int);
	virtual void resetState();
	void moveBottom(int);
	void moveTop(int);
	void moveLeft(int);
	void moveRight(int);
	virtual void autoMove(int, int);
	void setXDir(int);
	void setYDir(int);
	int getXDir();
	int getYDir();
	QRect getRect();
	QImage & getImage();
	virtual void collision(int&, int&);
	virtual void bulletCollision(int&);
};

#endif
