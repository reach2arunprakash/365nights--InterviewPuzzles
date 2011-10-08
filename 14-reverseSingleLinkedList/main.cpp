#include <iostream>
using namespace std;
struct Node
{
     int data;
     Node* next;
};

Node* newNode(int data)
{
     struct Node* node = (struct Node*)
	  malloc(sizeof(struct Node));
     node->data  = data;
     node->next  = NULL;
 
     return(node);
}

Node* reverse(Node*& header)
{
     Node* a = 0;
     Node* b = header;
     Node* c = header->next;

     while(c)
     {
	  b->next = a;
	  a = b;
	  b = c;
	  c = c->next;
     }
     b->next = a;
     return b;
}

int main ()
{
     Node * header = newNode(1);
     header->next = newNode(2);
     header->next->next = newNode(3);
     header->next->next->next = newNode(4);          
     Node * i = reverse(header);
     while(i)
     {
	  cout << i->data << endl;
	  i = i->next;
     }
}
