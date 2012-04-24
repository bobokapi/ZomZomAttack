/* This is the definition of the main game widget. */
#ifndef ZOMZOMATTACK_H
#define ZOMZOMATTACK_H

#include "szom.h"
#include "azom.h"
#include "gzom.h"
#include "seekzom.h"
#include "fastseekzom.h"
#include "shootzom.h"
#include "mcon.h"
#include "weapon.h"
#include "player.h"
#include "bullet.h"
#include <QWidget>
#include <QFrame>
#include <QKeyEvent>
#include <vector>

class ZomZomAttack : public QFrame
{
  Q_OBJECT

  public:
	ZomZomAttack(QWidget *parent = 0);
	~ZomZomAttack();
	void shoot(QPoint origin, QPoint target);

  protected:
	void paintEvent(QPaintEvent *event);
	void timerEvent(QTimerEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void levelIncrease();
	void startGame();
	void stopGame();
	void checkCollision();
	
  signals:
	void scoreChanged(int score);
	void healthChanged(int health);
	void levelChanged(int level);

  private:
	int timerId;
	Player* player;
	vector<Object*> zomzom;
	vector<Bullet*> zBullets;
	vector<Bullet*> pBullets;
	bool gameOver;
	bool gameStarted;
	int points;
	int health;
	int level;
};

#endif
