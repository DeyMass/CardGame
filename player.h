#ifndef PLAYER_H
#define PLAYER_H

#include <QTcpSocket>
#include <QObject>
#include <MyDeckList.h>

class	Player : public QObject
{
	Q_OBJECT
public:
	explicit Player(QObject *parent = 0);

	void start();

	void connect();

	int checkStatus();

signals:

public slots:

private:
	char			PlayerNum;
	char			WinCondition;
	//QList<Card>		*Hand;
	MyDeckList		*Hand;
	int				Status;
	QTcpSocket		*Socket;
};

#endif // CARD_H
