#include <iostream>
#include <assert.h>
using namespace std;

int fib(int n)
{
	 assert(n >= 0);
	 if (n <= 2)
		  return n - 1;

	 int a = 0;
	 int b = 1;
	 n -= 2;
	 while(n--)
	 {
		  int p = a + b;
		  assert(p >= b);
		  a = b;
		  b = p;
	 }
	 assert( b > 0 );
	 return b;
}


int main()
{

	 for (int i = 0; i < 100; ++i)
		  cout << fib(i) << endl;
	 return 0;
}
