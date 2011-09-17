#include <iostream>
using namespace std;

int find(int a[], int n)
{
	bool* checker = new bool[n];
	for (int i = 1; i <= n + 1; ++i)
	{
		checker[i] = false;
	}
	for (int i = 1; i <= n; ++i)
	{
		checker[a[i]] = true;
	}
	for (int i = 1; i <= n + 1; ++i)
	{
		if(!checker[i])
			return i;
	}
	delete[] checker;
}

int main(int argc, char *argv[])
{
	int a[] = {0,4, 5, 1, 2, 6};
	cout << find(a, 5) << endl;
    return 0;
}
