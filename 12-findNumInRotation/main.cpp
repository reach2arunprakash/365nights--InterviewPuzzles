#include <iostream>
#include <vector>

using namespace std;

template <typename I, typename T>
I lower_bound1(I first, I last, const T& value)
{
     size_t len = last - first;
	
     while (len > 0)
     {
	  I middle = first;
	  advance(middle, len >> 1);
	  if (*middle < *first)
	       if (value < * middle || value >= *first)
		    last = middle + 1;
	       else
		    first = middle;
	  else if (* middle < value)
	       first = middle + 1;
	  else
	       last = middle;

	  len = last - first;
     }
     return first;
}

int main()
{
     int a[] = {7, 8, 1, 2, 3, 4, 5, 6};
     vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

     vector<int>::iterator i;
     i = lower_bound1(v.begin(), v.end(), 7);
     cout << *i << endl;
     i = lower_bound1(v.begin(), v.end(), 8);     
     cout << *i << endl;
	
     return 0;
}
