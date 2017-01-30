#include "card.h"
//#include <QMatrix>

Card::Card(Suit s, Value v, QObject *parent) : QObject(parent)
{
	img = NULL;
	_Suit = s;
	_Val = v;
}

