#ifndef PLAYER_H
#define PLAYER_H

#include <headers/card.h>
#include <QList>
#include <QTcpSocket>

class Player{
private:
	QList<Card>	*hand;
	QTcpSocket	*socket;

public:
	Player();

	int	ConnectToServer();

	int SendData();

	int RecieveData(Card Recieved);

};

#endif // PLAYER_H
