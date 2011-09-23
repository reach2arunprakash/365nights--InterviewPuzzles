#include <iostream>
#include <vector>
using namespace std;

#define MAX_NUMBER 5

int findDuplicate(const vector<int>& v)
{
	bool check[MAX_NUMBER] = {false};

	vector<int>::const_iterator vi;
	
	for (vi = v.begin(); vi != v.end(); ++vi)
	{
		if(*vi < MAX_NUMBER)
			check[*vi] = true;
	}
	for (int i = 0; i < MAX_NUMBER; ++i)
	{
		if(!check[i])
			return i;
	}
}

int main(int argc, char *argv[])
{
    int a[MAX_NUMBER] = {0,1,2,2,4};
	vector<int> v(a, a + MAX_NUMBER);
	cout << findDuplicate(v) << endl;
    return 0;
}
