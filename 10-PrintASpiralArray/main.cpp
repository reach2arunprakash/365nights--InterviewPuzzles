#include <iostream>
#include <iomanip>
using namespace std;

void _print(int n, int l)
{

	if(l == 1)
	{
		for(int i = 0; i < n; i++)
			cout << n * n - i << " ";
		return;
	}
	if(l == n)
	{
		for(int i = n - 1; i >= 0; i--)
			cout << n * n - (2 * (n - 1)) - i << " ";
		return;
	}
	cout << n * n - (3 * (n - 1)) - (n - l) << " ";
	_print(n - 2, l - 1);
	cout << n * n - (n - 1) - (l - 1) << " ";
}

void print(int n)
{
	cout << setw(2)<< setiosflags(ios::right) << setfill('0');	
	for(int i = 1; i <= n; ++i)
	{
		_print(5, i);
		cout << '\n';
	}
}

int main()
{

	print(5);
}
