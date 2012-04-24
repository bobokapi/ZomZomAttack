/*
This is the definition of the ShootZom class. This class defines the behavior of the shooter ZomZom objects in the game. It inherits from ZomZom.
*/
#ifndef SHOOTZOM_H
#define SHOOTZOM_H

#include "zomzom.h"
#include "zomzomattack.h"
using namespace std;

class ZomZomAttack;

class ShootZom : public ZomZom {
  private:
	ZomZomAttack* game;
	int timeTillShoot;

  public:
	ShootZom(ZomZomAttack* zza);
	// also reset health
	void resetState();
	/* This overwrites the default automove so that the shooter zombie will fire a bullet towards the character. */
	virtual void autoMove(int px, int py);
};

#endif
