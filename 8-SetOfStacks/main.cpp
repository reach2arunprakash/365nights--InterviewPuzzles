#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

template <typename T>
class SetOfStack
{
private:
     stack< stack< T > > ss;
     const int MAX_SIZE;
     int size;
     void addStack()
	  {
	       stack< T >s;
	       ss.push(s);
	  }
public:
     SetOfStack(int size) : MAX_SIZE(size), size(0)
	  {
	       addStack();
	  }
     bool pop()
	  {
	       while(ss.size() > 0 && ss.top().size() == 0)
	       {
		    ss.pop();
	       }
	       if (ss.size() == 0)
		    return false;
	       ss.top().pop();
	       size--;
	       return true;
	  }

     T& top()
	  {
	       while(ss.top().size() == 0)
	       {
		    ss.pop();
	       }
	       return ss.top().top();
	  }

     void push(T& value)
	  {
	       if(ss.top().size() == MAX_SIZE)
	       {
		    assert(ss.top().size() <= MAX_SIZE);
		    addStack();
		    assert(ss.top().size() == 0);		    
	       }

	       size++;
	       ss.top().push(value);
	  }
};

int main()
{
     SetOfStack<int> ss(3);
     for(int i = 0; i < 10; i++)
     {
	  ss.push(i);
     }
     for(int i = 0; i < 10; i++)
     {
	  cout << ss.top() << endl;
	  ss.pop();
     }
     return 0;
}
