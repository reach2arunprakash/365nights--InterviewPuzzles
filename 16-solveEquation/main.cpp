#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

int getSolution(const vector<int> & v, int n)
{
     assert(v.size());
     assert(n);
     vector <vector<int> > dp;
     vector<int> row (v.size() + 1);
     for (int i = 0; i <= n; i ++)
	  dp.push_back(row);
     for (int i = 0; i <= n; i ++)
	  for (int j = 0; j <= v.size(); j++)
	       if ( i == 0)
		    dp[i][j] = 1;
	       else
		    dp[i][j] = 0;
     
     for (int i = 1; i <= n; i ++)
	  for (int j = 1; j <= v.size(); j++)
	       for (int k = i; k >= 0; k -= v[j - 1])
		    dp[i][j] += dp[k][j - 1];
     return dp[n][v.size()];
}

int main()
{
     int array[] = {2, 5};
     vector<int> v(array, array + sizeof(array) / sizeof(array[0]));
     cout << getSolution(v, 10) << endl;
}
