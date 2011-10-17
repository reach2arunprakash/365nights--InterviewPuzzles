#include <iostream>
#include <vector>

#include <stdlib.h>
#include <assert.h>
using namespace std;

template <class I>
void shuffle(I first, I last)
{
	assert(first <= last);
	I i = first;
	while (i != last)
	{
		I p = first;
		advance(p, rand() % (distance(first, i) + 1));
		swap(*p, *i);
		++i;
	}
}


int main()
{
	int array[] = {1, 2, 3, 4, 5};
	vector<int> v (array, array + sizeof(array)/sizeof(array[0]));
	shuffle(v.begin(), v.end());
	vector<int>::iterator i = v.begin();
	for (i = v.begin(); i < v.end(); ++i)
	{
		cout << *i << endl;
	}
}
