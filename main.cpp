#include "mainwindow.h"
#include <player.h>
#include <QApplication>
#include <defines.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	int ERROR_CODE;
	Player* pl;
	pl = new Player;
	pl->start();
	return a.exec();
}
