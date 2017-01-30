#ifndef MYDECKLIST_H
#define MYDECKLIST_H

#ifdef CLIENT
	#include <card.h>
#endif

struct List{
		Card* card;
		List* next;
	};

class MyDeckList
{
public:
private:
	List* head;
	int length;

public slots:
	void newMessage(); //КАК?!

public:
	MyDeckList();

	void add(Suit s, Value v);

	int getLength();

	Card** getCards();

};

#endif // MYDECKLIST_H
