#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> findSubArray(const vector<int>& v)
{
	vector<int>::const_iterator i;
	map<int, vector<int>::const_iterator > count;
	int sum = 0;
	for (i = v.begin(); i != v.end(); ++i)
	{
		sum += *i;
		if(0 == sum)
			return vector<int>(v.begin(), i + 1);
		if(count.find(sum) == count.end())
			count[sum] = i;
		else
			return vector<int>(count[sum] + 1, i + 1);
	}
	return vector<int>();
}

int main()
{
	int a[] = {7,0,3,-4,3,9};
	vector<int> v(a, a + sizeof(a)/sizeof(int));
	v = findSubArray(v);
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
}
	
