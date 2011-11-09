#include <vector>
#include <iostream>
using namespace std;

template <class I, class T>
I higher_bound(I first, I last, const T& value)
{
	 size_t len = last - first;

	 I middle;
	 while (len > 0)
	 {
		  middle = first;
		  len = last - first;
		  advance(middle, len>>1);
		  if(value >= * middle)
			   first = middle + 1;
		  else
			   last = middle;
	 }

	 return first;
}

int main()
{
	 int array[] = {1,2, 3 ,4 ,4 ,5};

	 vector<int> v (array, array + sizeof(array)/sizeof(array[0]));
	 cout << *higher_bound(v.begin(), v.end(), 4) << endl;
	 
}
