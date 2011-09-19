#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template <typename Iterator, typename T>
Iterator lower_bound(Iterator first, Iterator last, const T& value, random_access_iterator_tag)
{
	typedef typename iterator_traits< Iterator >::difference_type Distance;
	Iterator middle;
	Distance len = last - first;
	Distance half;
	while(len > 0)
	{
		half = len >> 1;
		middle = first + half;
		if (value > *middle)
		{
			first = ++middle;
			len = len - half - 1;
		}
		else
		{
			len = half;
		}
	}
	return first;
}

template <typename Iterator, typename T>
bool binarySearch(Iterator first, Iterator last, const T& value)
{
	Iterator result = lower_bound(first, last, value, typename iterator_traits< Iterator >::iterator_category());
	return ( result != last ) && (*result == value);
}

int main()
{
	int a[] = {1, 3, 5, 7, 9};
	vector<int>  iv(a, a + 5);
	cout << binarySearch(iv.begin(), iv.end(), 1) << endl;
	cout << binarySearch(iv.begin(), iv.end(), 2) << endl;
	cout << binarySearch(iv.begin(), iv.end(), 3) << endl;
	cout << binarySearch(iv.begin(), iv.end(), 4) << endl;
	cout << binarySearch(iv.begin(), iv.end(), 5) << endl;
	cout << binarySearch(iv.begin(), iv.end(), 6) << endl;
	cout << binarySearch(iv.begin(), iv.end(), 7) << endl;	
}
