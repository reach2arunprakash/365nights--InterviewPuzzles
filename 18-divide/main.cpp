#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

int multiply(int n, int m)
{
     int r = 0;
     for (int i = 0; i < m; ++i)
	  r += n;
     return r;
}

int divide(int n, int m)
{
     stack<int> s;
     s.push(1);

     while(multiply(s.top() + s.top(), m) < n)
	  s.push(s.top() + s.top());

     int b = s.top();
     s.pop();

     while(true)
     {
	  if(multiply (b+s.top(), m) < n)
	       b += s.top();
	  else if (multiply (b + s.top(), m) == n)
	       return  b + s.top();
	  assert(s.size());
	  s.pop();
     }
}

int main()
{
     cout << divide(155, 5) << endl;
     return 0;
}
