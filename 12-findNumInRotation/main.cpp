#include <iostream>
#include <vector>

using namespace std;

template <typename I, typename T>
I lower_bound1(I first, I last, const T& value)
{
	size_t len = last - first;
	I middle = first;
	
	while (len > 0)
	{
		advance(middle, len >> 1);

		if (*middle < *first)
			first = middle;
		else if (* middle < value)
			first = middle + 1;
		else
			last = middle + 1;

		len = last - first;
	}
	return middle;
}

int main()
{
	int a[] = {4, 5, 6 ,7, 1, 2, 3};

	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	vector<int>::iterator i;
	i = lower_bound1(v.begin(), v.end(), 1);
	cout << *i << endl;
	
	return 0;
}
