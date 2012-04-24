/* This is the definition of the game window widget. */
#ifndef ZOMZOMATTACKWINDOW_H
#define ZOMZOMATTACKWINDOW_H

#include "zomzomattack.h"
#include <QtGui>
#include <QFrame>

class QLCDNumber;
class QLabel;
class QPushButton;

class ZomZomAttack;

class ZomZomAttackWindow : public QWidget {
	Q_OBJECT

  public:
	ZomZomAttackWindow();

  private:
	QLabel *createLabel(const QString &text);
	ZomZomAttack *board;
	QLCDNumber *scoreLcd;
	QLCDNumber *healthLcd;
	QLCDNumber *levelLcd;
};

#endif
