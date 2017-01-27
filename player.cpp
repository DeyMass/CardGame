#include "player.h"
#include <defines.h>
#include <QThread>
#include <QString>
#include <QApplication>

Player::Player(QObject *parent) : QObject(parent)
{
	Socket = new QTcpSocket(this);
	Socket->connectToHost(SERVER_ADDRESS, SERVER_PORT);
	if (Socket->waitForConnected(TIMEOUT_MS)){
		Socket->write(FIRST_MESSAGE, MESSAGE_LENGTH);
		Socket->flush();
	} else {
		printf("\nConnection timed out...");
		QThread::msleep(1);
		QApplication::exit(CONNECTION_ERROR);
	}
}

//Стркутура сообщения:
//"p<НомерИгрока>;w<win кондиция>;
//c<id карты>"
//Номер игрока:
//	1/2
//ID карты:
//	<Масть>:<Номинал>
//win кондиция: *Нужна на случай победы оппонента*
//	0/1/2
//Масть:
//	0/1/2/3
//Номинал:
//	0 - 12
//Пример:
//p1;w0;c2:6
//0123456789(10)
//Сообщение - не больше 11 символов
void Player::start()
{
	char msg[MESSAGE_LENGTH];
	Socket->read(msg, MESSAGE_LENGTH);
	int IT;
	IT = 1;
	PlayerNum = msg[IT] - '0';
	IT = 4;
	WinCondition = msg[IT] - '0';
	IT = 7;
	//Создание карты и добавление её к руке
}
