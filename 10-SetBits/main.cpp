#include <iostream>
#include <iomanip>
using namespace std;

int SetBit(int n, int m, int i, int j)
{
	int max = ~0;
	
	int mask = max << i | max << j;
	n &= mask;
	return (n | m << i);
}


int main()
{
	cout << SetBit(512, 21, 2, 6) << endl;
	return 0;
}
