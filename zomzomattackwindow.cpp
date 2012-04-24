/* This is the definition of the game window widget. */
#include "zomzomattackwindow.h"
#include <QDesktopWidget>
#include <QApplication>

ZomZomAttackWindow::ZomZomAttackWindow() {
	board = new ZomZomAttack(this);
	board->setFixedSize(500, 400);

	scoreLcd = new QLCDNumber(8);
	scoreLcd->setSegmentStyle(QLCDNumber::Filled);
	healthLcd = new QLCDNumber();
	healthLcd->setSegmentStyle(QLCDNumber::Filled);
	levelLcd = new QLCDNumber();
	levelLcd->setSegmentStyle(QLCDNumber::Filled);

	connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
	connect(board, SIGNAL(healthChanged(int)), healthLcd, SLOT(display(int)));
	connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(board, 0, 0, 6, 1 );
	layout->addWidget(createLabel(tr("LEVEL")), 0, 2);
	layout->addWidget(levelLcd, 1, 2);
	layout->addWidget(createLabel(tr("Health")), 2, 2);
	layout->addWidget(healthLcd, 3, 2);
	layout->addWidget(createLabel(tr("SCORE")), 4, 2);
	layout->addWidget(scoreLcd, 5, 2);
	setLayout(layout);

	setWindowTitle(tr("ZomZomAttack"));
}

/* This method creates a label with a given input */
QLabel *ZomZomAttackWindow::createLabel(const QString &text) {
	QLabel *lbl = new QLabel(text);
	lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	return lbl;
}
