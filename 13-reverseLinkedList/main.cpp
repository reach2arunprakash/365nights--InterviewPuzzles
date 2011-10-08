#include <iostream>
using namespace std;
struct Node
{
     int data;
     Node* pref;
     Node* next;
};

Node* newNode(int data)
{
     struct Node* node = (struct Node*)
	  malloc(sizeof(struct Node));
     node->data  = data;
     node->pref  = NULL;
     node->next  = NULL;
 
     return(node);
}

void reverse(Node*& header)
{
     Node * i = header;
     while( i -> next)
     {
	  i = i->next;
     }
     header = i;
     while (i)
     {
	  Node * temp = i -> next;
	  i -> next = i -> pref;
	  i -> pref = temp;
	  i = i -> next;
     }
}

int main ()
{
     Node * head = newNode(1);
     reverse(head);
     Node * i = head;
     while(i)
     {
	  cout << i->data << endl;
	  i = i->next;
     }
}


