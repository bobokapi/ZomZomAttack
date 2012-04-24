#include "zomzomattackwindow.h"
#include <QDesktopWidget>
#include <QApplication>

/*
This method centers the window.  This method is taken from the Qt breakout game tutorial found here: http://zetcode.com/tutorials/qt4tutorial/breakoutgame/
*/
void center(QWidget &widget) {
	int x, y;
	int screenWidth;
	int screenHeight;

	int WIDTH = 800;
	int HEIGHT = 450;

	QDesktopWidget *desktop = QApplication::desktop();

	screenWidth = desktop->width();
	screenHeight = desktop->height();

	x = (screenWidth - WIDTH) / 2;
	y = (screenHeight - HEIGHT) / 2;

	widget.setGeometry(x, y, WIDTH, HEIGHT);
	widget.setFixedSize(WIDTH, HEIGHT);
}

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);  
	
	ZomZomAttackWindow window;
	
	window.show();
	center(window);

	return app.exec();
}
