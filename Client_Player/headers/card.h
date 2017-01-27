#ifndef CARD_H
#define CARD_H

#include <QImage>
#include <headers/suit.h>


class Card
{
private:
	QImage	*image;
	int		Card_Suit;
	int		value;
public:
	Card();

	void	setSuit(Suit s, Value val, QImage* img);

	Suit	getCardSuit();
	Value	getCardValue();
};

#endif // CARD_H
