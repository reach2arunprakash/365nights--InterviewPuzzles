#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasSum(vector<int> & v, int sum)
{
     
     sort(v.begin(), v.end());
     for (int i = 0; i < v.size() - 2; i++)
     {
	  int n = v[i];
	  int j = i + 1;
	  int k = v.size() - 1;
	  while( k != j)
	  {
	       if (v[j] + v[k] + n > sum)
		    k --;
	       else if (v[j] + v[k] + n < sum)
		    j ++;
	       else
		    return true;//find it ! so happy!
		    
	  }
     }
     return false;
}

int main()
{
     int array[]={1,2,3,4,5,6,7,8};
     vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
     cout << hasSum(v, 10) << endl;
     cout << hasSum(v, 100) << endl;
     cout << hasSum(v, -1) << endl;          
}
