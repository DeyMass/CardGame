#include "MyDeckList.h"

MyDeckList::MyDeckList()
{
	head = NULL;
	length = 0;
}

void MyDeckList::add(Suit s, Value v){
	List* p = head;
	while(p->next){
		p = p->next;
	}
	p->next = new List;
	p = p->next;
	p->card = new Card(s,v);
	p->next = NULL;
	length++;
}

Card** MyDeckList::getCards(){
	Card** Result;
	Result = new Card*[length];
	int it = 0;
	List* p = head;
	while(p){
		Result[it] = p->card;
		p = p->next;
	}
	return Result;
}

int MyDeckList::getLength(){return length;}
