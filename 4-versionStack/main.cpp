#include <iostream>
using namespace std;

enum Operation{PUSH, POP};

struct Node
{
	 int value;
	 Node* prev;
	 Node* next;
	 Node* top;
	 Operation op;
};

class VersionStack
{
private:
	 Node* head;
	 Node* tail;
	 int totalVersion;
public:
	 VersionStack():head(0), tail(0), totalVersion(0)
		  {}
	 
	 void push(int value)
		  {
			   if(head == 0)
			   {
					head = new Node();
					tail = head;
					head->prev = 0;
			   }
			   else
			   {
					tail->next = new Node();
					tail->next->prev = tail;
					tail = tail->next;
			   }
			   tail->top = tail;
			   tail->op = PUSH;
			   tail->value = value;
			   tail->next = 0;
			   ++totalVersion;
		  }
	 bool pop()
		  {
			   if(head == 0)
					return false;
			   if(tail->prev == 0)
					return false;
			   tail->next = new Node();
			   tail->next->op = POP;
			   tail->next->prev = tail;
			   tail->next->top = tail->top->prev;
			   while(tail->next->top && tail->next->top->op == POP)
					tail->next->top = tail->next->top->top;
			   tail = tail->next;
			   if(tail->top)
					tail->value= tail->top->value;
			   ++totalVersion;
			   return true;
		  }
	 bool top(int& value)
		  {
			   if (head == 0)
					return false;
			   if (tail->prev == 0)
					return false;
			   value = tail->value;
			   return true;
		  }
	 bool print(int version, int& value)
		  {
			   int i = 0;
			   if (head == 0)
					return false;
			   Node* now = head;
			   for(int i = 1; i != version; ++i)
			   {
					now = now -> next;
					if (now == 0)
						 return false;					
			   }
			   if(now->top == 0)
					return false;
			   value = now->value;
			   return true;
		  }
	 int size() const
		  {
			   return totalVersion;
		  }
};



int main()
{
	 VersionStack vs;
	 vs.push(1);
	 vs.push(2);
	 vs.push(3);
	 vs.pop();
	 vs.pop();
	 vs.push(4);
	 vs.pop();
	 vs.pop();
	 for(int i = 1; i <= vs.size(); ++i)
	 {
		  int v;
		  if(vs.print(i, v))
			  cout << v << " " << endl;
	 }
	 return 0;
}
