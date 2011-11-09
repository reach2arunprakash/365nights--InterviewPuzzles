#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class I>
int countK(I first, I last, int k)
{
	sort(first, last);
	I i = first;
	I j = first;
	int count = 0;
	while(j != last && i != last)
	{
		if(*i - *j < k)
			++i;
		else if(*i - *j > k)
			++j;
		else
		{
			count ++;
			++i;
		}
	}
	return count;
}

int main(int argc, char *argv[])
{
    int n, k;
	cin >> n >> k;
	vector<long> v;
	for (int i = 0; i < n; ++i)
	{
		long t;
		cin >> t;
		v.push_back(t);
	}
	cout << countK(v.begin(), v.end(), k) << endl;
    return 0;
}
