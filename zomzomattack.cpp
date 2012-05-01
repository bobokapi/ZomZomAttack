/* This is the definition of the main game widget. */
#include "zomzomattack.h"
#include <iostream>
#include <vector>
#include <QPainter>
#include <QPalette>
#include <QBrush>
#include <QApplication>

/* The constuctor creates the player, initializes the boolean values, and initializes the points, lives, and health */
ZomZomAttack::ZomZomAttack(QWidget *parent) : QFrame(parent) {
	setFocusPolicy(Qt::StrongFocus);
	gameOver = FALSE;
	gameStarted = FALSE;
	player = new Player();
	
	points = 0;
	health = 100;
	level = 0;
}

/* The destructor deletes heap memory */
ZomZomAttack::~ZomZomAttack() {
	delete player;
	for (int i = 0; i < zomzom.size(); i++) {
		delete zomzom[i];
	}
	zomzom.clear();
	for (int i = 0; i < zBullets.size(); i++) {
		delete zBullets[i];
	}
	zBullets.clear();
	for (int i = 0; i < pBullets.size(); i++) {
		delete pBullets[i];
	}
	pBullets.clear();
}

/* When a paint event is generated, this method checks to see if the game is over and gives an appropriate message or else draws the player and Objects from the array */
void ZomZomAttack::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	
	if (gameOver) painter.drawPixmap(rect(), QPixmap("gameover.png"));
	else {
		if (level == 1) painter.drawPixmap(rect(), QPixmap("level1.png"));
		else if (level == 2) painter.drawPixmap(rect(), QPixmap("level2.png"));
		else if (level == 3) painter.drawPixmap(rect(), QPixmap("level3.png"));
		else if (level == 4) painter.drawPixmap(rect(), QPixmap("level4.png"));
		else painter.drawPixmap(rect(), QPixmap("start.png"));
		
		painter.drawImage(player->getRect(), player->getImage());
		for (int i = 0; i < zomzom.size(); i++)
			painter.drawImage(zomzom[i]->getRect(), zomzom[i]->getImage());
		for (int i = 0; i < zBullets.size(); i++)
			painter.drawImage(zBullets[i]->getRect(), zBullets[i]->getImage());
		for (int i = 0; i < pBullets.size(); i++)
			painter.drawImage(pBullets[i]->getRect(), pBullets[i]->getImage());
	}
}

/* When there is a timer event, this method automatically moves each Object, checks for collisions, and then calls the repaint() method */
void ZomZomAttack::timerEvent(QTimerEvent *event) {
	int px = player->getRect().x();
	int py = player->getRect().y();
	for (int i = 0; i < zomzom.size(); i++) zomzom[i]->autoMove(px, py);
	for (int i = 0; i < zBullets.size(); i++) {
		zBullets[i]->autoMove(px, py);
		if (zBullets[i]->isDone()) zBullets.erase(zBullets.begin() + i);
	}
	for (int i = 0; i < pBullets.size(); i++) {
		pBullets[i]->autoMove(px, py);
		if (pBullets[i]->isDone()) pBullets.erase(pBullets.begin() + i);
	}
	checkCollision();
	repaint();
	
	if (level == 1 && points > 500000) levelIncrease();
	if (level == 2 && points > 1250000) levelIncrease();
	if (level == 3 && points > 5000000) levelIncrease();
	emit scoreChanged(points);
	emit healthChanged(health);
	emit levelChanged(level);
}

/* This method adds a bullet to the zomzom bullet vector. It is called by the ShootZom's autoMove method. */
void ZomZomAttack::shoot(QPoint origin, QPoint target) {
	zBullets.push_back(new Bullet(origin, target));
}

/* When there is a key press event, this method checks for player commands such as movement, game restart, and game exit */
void ZomZomAttack::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    	case Qt::Key_Q:
		{
			health += 100;
		}
		break;
	case Qt::Key_A:
		{
			int x = player->getRect().x();
			for (int i=1; i<=10; i++) player->moveLeft(x--);
		}
		break;
	case Qt::Key_D:
		{
			int x = player->getRect().x();
			for (int i=1; i<=10; i++) player->moveRight(x++);
		}
		break;
	case Qt::Key_W:
		{
			int y = player->getRect().y();
			for (int i=1; i<=10; i++) player->moveTop(y--);
		}
		break;
	case Qt::Key_S:
		{
			int y = player->getRect().y();
			for (int i=1; i<=10; i++) player->moveBottom(y++);
		}
		break;
	case Qt::Key_Space:
		{
			startGame();
		}
		break;
	case Qt::Key_Escape:
		{
			qApp->exit();
		}
		break;
	default:
		QWidget::keyPressEvent(event);
	}
}

/* When The player clicks, a bullet is fired from the player's location in the direction of the click */
void ZomZomAttack::mousePressEvent(QMouseEvent *event) {
	pBullets.push_back(
		new Bullet(QPoint(player->getRect().x(), player->getRect().y()), event->pos()));
}

/* This method restarts the game by moving the player to the default position and resetting default game values */
void ZomZomAttack::startGame() { 
	if (!gameStarted) {
		player->resetState();
		
		for (int i = 0; i < zomzom.size(); i++) {
			delete zomzom[i];
		}
		zomzom.clear();
		for (int i = 0; i < zBullets.size(); i++) {
			delete zBullets[i];
		}
		zBullets.clear();
		for (int i = 0; i < pBullets.size(); i++) {
			delete pBullets[i];
		}
		pBullets.clear();
		
		for (int i = 0; i < 3; i++) zomzom.push_back(new SZom());
		for (int i = 0; i < 4; i++) zomzom.push_back(new AZom());
		for (int i = 0; i < 3; i++) zomzom.push_back(new GZom());
		for (int i = 0; i < 3; i++) zomzom.push_back(new Weapon());
		for (int i = 0; i < 3; i++) zomzom.push_back(new MCon());
		
		points = 0;
		health = 100;
		level = 1;
		gameOver = FALSE;
		gameStarted = TRUE;
		timerId = startTimer(35);
	}
}

/* This method stops the game by killing the timer and setting the game over boolean to true so that when the paint method happens, the game over message will appear */
void ZomZomAttack::stopGame() {
	killTimer(timerId);    
	gameOver = TRUE;      
	gameStarted = FALSE;
}

/* This method checks for collisions between the player and zomzoms or zomzom bullets and between zomzoms and player bullets, and then calls the appropriate collision methods. */
void ZomZomAttack::checkCollision() {
	for (int i = 0; i < zomzom.size(); i++) {
		if ((player->getRect()).intersects(zomzom[i]->getRect())) {  
			zomzom[i]->collision(points, health);
		} else {
			for (int j = 0; j < pBullets.size(); j++) {
				if ((zomzom[i]->getRect()).intersects(pBullets[j]->getRect())) {  
					zomzom[i]->bulletCollision(points);
					delete pBullets[j];
					pBullets.erase(pBullets.begin() + j);
				}
			}
		}
	}
	for (int i = 0; i < zBullets.size(); i++) {
		if ((player->getRect()).intersects(zBullets[i]->getRect())) {  
			health -= 10;
			delete zBullets[i];
			zBullets.erase(zBullets.begin() + i);
		} else {
			for (int j = 0; j < pBullets.size(); j++) {
				if ((pBullets[j]->getRect()).intersects(zBullets[i]->getRect())) {
					delete pBullets[j];
					pBullets.erase(pBullets.begin() + j);
					delete zBullets[i];
					zBullets.erase(zBullets.begin() + i);
				}
			}
		}
	}
	
	if (health < 1) {
		health = 0;
		stopGame();
	}
}

/* This method increases the level by first clearing the vectors and then adding the correct new configuration of ZomZoms */
void ZomZomAttack::levelIncrease() {
	level++;
	for (int i = 0; i < zomzom.size(); i++) {
		delete zomzom[i];
	}
	zomzom.clear();
	for (int i = 0; i < zBullets.size(); i++) {
		delete zBullets[i];
	}
	zBullets.clear();
	for (int i = 0; i < pBullets.size(); i++) {
		delete pBullets[i];
	}
	pBullets.clear();
	
	if (level == 2) {
		for (int i = 0; i < 3; i++) zomzom.push_back(new GZom());
		for (int i = 0; i < 2; i++) zomzom.push_back(new SeekZom());
		for (int i = 0; i < 3; i++) zomzom.push_back(new MCon());
	} else if (level == 3) {
		zomzom.push_back(new FastSeekZom());
		zomzom.push_back(new ShootZom(this));
		for (int i = 0; i < 2; i++) zomzom.push_back(new MCon());
	} else {
		for (int i = 0; i < 2; i++) zomzom.push_back(new FastSeekZom());
		for (int i = 0; i < 2; i++) zomzom.push_back(new ShootZom(this));
	}
}
