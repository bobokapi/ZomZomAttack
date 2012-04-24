/*
This is the definition of the ShootZom class. This class defines the behavior of the shooter ZomZom objects in the game. It inherits from ZomZom.
*/
#include "shootzom.h"
#include <QPoint>
using namespace std;

/* This constructor takes a pointer to the ZomZomAttack object as a parameter so that it can call the shoot method from autoMove */
ShootZom::ShootZom(ZomZomAttack *zza): ZomZom(1,20) {
	this->game = zza;
	Object::dpoints = 203409;
	Object::dhealth = -30;
	timeTillShoot = 20;
	
	image.load("shootzom.png");
	rect = image.rect();
	resetState();
}

// also reset health, timeTillShoot
void ShootZom::resetState() {
	Object::resetState();
	ZomZom::health = 20;
	timeTillShoot = 20;
}

/* This overwrites the default automove so that the shooter zombie will fire a bullet towards the character. */
void ShootZom::autoMove(int px, int py) {
	Object::autoMove(px, py);
	if (timeTillShoot == 0) {
		game->shoot(QPoint(rect.x(), rect.y()), QPoint(px, py));
		timeTillShoot = 20;
	} else timeTillShoot--;
}