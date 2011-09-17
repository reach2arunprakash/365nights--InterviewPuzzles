#include <iostream>
#include <assert.h>
using namespace std;

int find(int a[], int m, int n)
{
	if (m == n)
	{
		if (a[m] < m)
			return m;
		if (a[m] == m)
			return m + 1;
		if (a[m] > m)
			return m;
	}

	int k = (m + n) / 2;
	if (a[k] > k)
		return find(a, m, k - 1);
	if (a[k] == k)
		return find(a, k + 1, n);
	assert(false);
}

int main(int argc, char *argv[])
{
    int a[] = {0, 1, 3, 4, 5, 6,  7};
	cout << find(a, 1, 6) << endl;
    return 0;
}
