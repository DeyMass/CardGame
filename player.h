#ifndef PLAYER_H
#define PLAYER_H

#include <QTcpSocket>
#include <QObject>
#include <card.h>

class Player : public QObject
{
	Q_OBJECT
public:
	explicit Player(QObject *parent = 0);

	void start();

signals:

public slots:

private:
	char			PlayerNum;
	char			WinCondition;
	//QList<Card>	*Hand;
	int				Status;
	QTcpSocket		*Socket;
};

#endif // CARD_H
