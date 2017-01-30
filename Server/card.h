#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <../defines.h>

class Card : public QObject
{
	Q_OBJECT

private:
	QImage	*img;
	int		x;
	int		y;
	Suit	_Suit;
	Value	_Val;

public:
	explicit Card(Suit s, Value v, QObject *parent = 0);

	void set_x(int newX);
	void set_y(int newY);

	Suit getSuit(){return _Suit;}
	Value getValue(){return _Val;}


signals:

public slots:

};

#endif // CARD_H
