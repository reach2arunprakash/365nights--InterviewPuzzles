#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool findArray(vector<int>& v, int& a, int& b, int sum)
{
     vector<int>::const_iterator i;
     vector<int>::const_reverse_iterator j;
     sort(v.begin(), v.end());
     for(i = v.begin(), j = v.rbegin(); i != (j.base() - 1); ++i, ++j)
     {
	  if((*i + *j) == sum)
	  {
	       a = *i;
	       b = *j;
	       return true;
	  }
	  if((*i + *j) > sum)
	       j++;
	  else
	       i++;
     }
     return false;
}

int main()
{
     int a, b;
     int array[] = {4, 3, 6, 1, 0, 7};
     vector<int> v(array, array + 6);
     findArray(v, a, b, 7);
     cout << a << " " << b << endl;
}
