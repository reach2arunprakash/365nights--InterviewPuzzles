#include <list>
#include <iostream>
#include <vector>
using namespace std;

template<class Iterator>
Iterator findNth(Iterator start, Iterator end, int n)
{
	Iterator first = start;
	Iterator second = start;
	for (int i = 0; i < n; ++i)
		++first;
	for(; first!=end; ++first, ++second)
	{
		;
	}
	return second;
}



int main(int argc, char *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
	list< int > iv(a, a+10);
	cout << *findNth(iv.begin(), iv.end(), 5) << endl;
    return 0;
}

