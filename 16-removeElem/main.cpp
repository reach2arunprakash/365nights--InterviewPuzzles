#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

template <typename I, typename T>
I removeElem(I first, I last, const T& elem)
{
     I a = last;
     I b = first;

     while( b != a)
     {
	  if (*b != elem)
	       ++b;
	  else
	  {
	       --a;
	       swap(*a, *b);
	  }
     }
     return a;
}

int main()
{
     int array[] = {3, 5, 1, 5, 2, 3, 4};
     vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
     
     vector<int>::iterator end = removeElem(v.begin(), v.end(), 5);
     vector<int>::iterator i;
     for (i = v.begin(); i != end; ++i)
     {
	  cout << *i << endl;
     }
     return 0;
}     
