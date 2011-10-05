#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename Iterator, typename T>
void triblecut(Iterator first, Iterator last, const T& value)
{
	if(first == last)
		return;
	Iterator i = first - 1;
	Iterator j = last;
	while(first != j)
	{
		if(*first > value)
			first++;
		else if(*first < value)
		{
			++i;
			swap(*i, *first);
			first++;
		}else
		{
			--j;
			swap(*j, *first);
		}
	}
}

int main()
{
	int a[] = {1,5,4,2,3,6,3,7,1,2};
	vector<int> v(a, a + sizeof(a)/sizeof(int));
	triblecut(v.begin(), v.end(), 3);
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	return 0;
}
