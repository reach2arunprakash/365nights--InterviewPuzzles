#include <iostream>
using namespace std;

struct Node
{
	Node* next;
	Node* rand;
};

struct List
{
	Node* head;
};

List copyList(List* l)
{
	Node* i = l->head;
	while(i)
	{
		Node* n = new Node();
		n->next = i->next;
		i->next = n;
		n->rand = i->rand;
		i = i->next->next;
	}
	List newL;
	newL.head = l->head->next;
	i = l->head;
	while(i)
	{
		i->next->rand = i->rand->next;
		i = i->next->next;
	}
	i = l->head;
	while(i)
	{
		i->next = i->next->next;
		if(i->next->next)
			i->next->next = i->next->next->next;
		i = i->next;
	}
	i = l->head;

}
