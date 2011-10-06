#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateArray(vector<int>& arr, int r)
{
     r = r%arr.size();
     reverse(arr.begin(), arr.end());
     reverse(arr.begin(), arr.begin() + r);
     reverse(arr.begin() + r, arr.end());
}

int main()
{
     int a[] = {1, 2, 3, 4, 5};
     vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
     rotateArray(v, 2);
     vector<int>::const_iterator i;
     for (i = v.begin(); i != v.end(); ++i)
	  cout << *i << endl;
     return 0;
}
