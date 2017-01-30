#define CLIENT

#include "mainwindow.h"
#include <player.h>
#include <QApplication>
#include <defines.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	Player* pl;
	pl = new Player;
	pl->connect();
	if (pl->checkStatus() == !READY_FOR_START){
		system("echo Connection timed out! && pause");
		return -1;
	}
	else
		pl->start();
	w.show();
	//while(pl->checkStatus() != GAME_END)
	//	pl->tick();
	return 1;
}
