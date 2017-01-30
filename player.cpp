#include "player.h"
#include <defines.h>
#include <QThread>
#include <QString>
#include <QApplication>

Player::Player(QObject *parent) : QObject(parent)
{
	Socket = new QTcpSocket(this);
//	Hand = new QList<Card>;
	Hand = new MyDeckList;
	//Hand->clear();
	Status = READY_FOR_CONECT;
}

int Player::checkStatus(){ return Status; }

void Player::connect(){
	Socket->connectToHost(SERVER_ADDRESS, SERVER_PORT);
	if (Socket->waitForConnected(TIMEOUT_MS)){
		Socket->write(FIRST_MESSAGE, MESSAGE_LENGTH);
		Socket->flush();
		Status = READY_FOR_START;
	} else {
		printf("\nConnection timed out...");
		Status = !READY_FOR_START;
	}
}

//Первое сообщение - начальная рука
//p<НомерИгрока>c<Количество_Карт>-<id_карты1><...>
//p1;c22:1,2:3
void Player::start()
{	
	char msg[MESSAGE_LENGTH];
	Socket->read(msg, MESSAGE_LENGTH);
	PlayerNum = msg[1] - 48;
	WinCondition = 0;
	int Iterator = 5;
	for (;Iterator < msg[4] - 48;)
		if (msg[Iterator + 3] != ','){
			Hand->add((Suit)(msg[Iterator] - 48), (Value)(msg[Iterator + 2] - 48));
//			Hand->insert(Hand->length(), new Card);
			Iterator += 4;
		} else {
//			Hand += new Card((Suit)(msg[Iterator] - 48), (Value)((msg[Iterator + 2] - 48)*10 + msg[Iterator + 3]));
			Iterator += 5;
		}
	//Создание карты и добавление её к руке
}


//Стркутура сообщения:
//"n<Количество_карт>;w<win кондиция>;
//c<id карты>,<...>"
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
//n2;w0;c2:6,1:1
//0123456789(10)
//Сообщение - не больше 11 символов
void Player::recieveMsg(){
	char msg[MESSAGE_LENGTH];
	Socket->read(msg, MESSAGE_LENGTH);
	WinCondition = msg[4] - 48;
	//Обработка сообщения
}
