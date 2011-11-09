#include <assert.h>
#include <iostream>
using namespace std;

void increment(char * a)
{
	assert(a);
	int i = 0;
	while(a[i])
		i ++;
	i--;
	while(i >= 0 && a[i] == '7')
	{
		a[i] = '0';
		i --;
	}	
	if (i < 0)
		return;
	else
		a[i]++;
}

int main()
{
	char a[]="177";
	increment(a);
	
	cout << a << endl;
}
