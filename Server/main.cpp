#include <QCoreApplication>
#include <QTcpSocket>
#include <QTcpServer>

#define SERVER

#include <../defines.h>
#include <card.h>

void SimpleShuffle(Card** &Deck){
	Card** Result;
	Result = new Card*[DECK_SIZE];
	for (int i = 0; i < DECK_SIZE; i++)
		Result[i] = NULL;
	int Count = 0;
	while(Count < DECK_SIZE){
		int RandomNum = rand() % DECK_SIZE;
		if (Result[RandomNum] == NULL){
			Result[RandomNum] = Deck[Count];
			Count++;
		}
	}
	Deck = Result;
}

char* createMSG(Card** Deck){
	msg[MESSAGE_LENGTH] = "c";
	msg[1] = 48 + START_HAND;
	int iterator = 2;
	int DrawCount = 0;
	for(int i = DECK_SIZE - 1; i >= 0; i--){
		if (Deck[i] != NULL){
			msg[iterator++] = 48 + Deck[i]->getSuit();
			msg[iterator++] = ':'
			if (Deck[i]->getValue() >= 10){
				msg[iterator++] = 49;
				msg[iterator++] = 48 + (Deck[i]->getValue() % 10);
				msg[iterator++] = ','
			}//УЧЕСТЬ ВСЁ!
		}

	}
}

int main(int argc, char *argv[])
{
	Card** Deck;
	Deck = new Card*[DECK_SIZE];
	//Deck[0] = new Card((Suit)0, (Value)0, NULL);
	int Count = 0;
	for (int s = 0; s <= 3; s++)
		for (int v = (int)_6; v <= (int)A; v++)
			Deck[Count++] = new Card((Suit)s, (Value)v, NULL);

	SimpleShuffle(Deck);

	for (int i = 0; i < DECK_SIZE; i++)
		printf("%i %i\n",Deck[i]->getSuit(), Deck[i]->getValue());

	//Deck - Общак

	QTcpServer* Serv;
	Serv = new QTcpServer;
	Serv->setMaxPendingConnections(2);
	Serv->listen(QHostAddress::Any, SERVER_PORT);

	QTcpSocket* player1;
	QTcpSocket* player2;

	//Карты - верхние несколько.
	//

	if (Serv->waitForNewConnection(TIMEOUT_MS)){
		player1 = Serv->nextPendingConnection();
		char msg[MESSAGE_LENGTH];
		player1->read(msg, MESSAGE_LENGTH);
		if (strcmp(msg, FIRST_MESSAGE) == 0)
			player1->write("p1");//+Начальная рука
	}

	if (Serv->waitForNewConnection(TIMEOUT_MS)){
		player2 = Serv->nextPendingConnection();
		char msg[MESSAGE_LENGTH];
		player2->read(msg, MESSAGE_LENGTH);
		if (strcmp(msg, FIRST_MESSAGE) == 0)
			player2->write("p2");//+Начальная рука
	}
	//player1->write("");

	return 0;
}
