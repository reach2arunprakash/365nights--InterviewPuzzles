#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

void Merge(vector<int> & v1, vector<int>& v2)
{
     int n = v1.size() + v2.size();
     int n1 = v1.size() - 1;
     int n2 = v2.size() - 1;
     v1.resize(n);
     n -- ;
     while (n1 >= 0 && n2 >= 0)
     {
	  if (v1[n1] > v2[n2])
	       v1[n--] = v1[n1--];
	  else
	       v1[n--] = v2[n2--];
     }
     while (n1 >= 0)
	  v1[n--] = v1[n1--];
     while (n2 >= 0)
	  v1[n--] = v2[n2--];
     assert(n1 == -1 && n2 == -1 && n == -1);
}

int main()
{
     int array1[] = {1, 3, 5, 7, 9};
     int array2[] = {2, 4, 6, 8};
     vector<int> v1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
     vector<int> v2(array2, array2 + sizeof(array2) / sizeof(array2[0]));
     Merge(v1, v2);
     for (int i = 0; i < v1.size(); ++i)
	  cout << v1[i] << endl;
}
