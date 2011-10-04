#include <string>
#include <vector>
#include <iostream>
using namespace std;

string findSubString(const string& a, const string& b)
{
     size_t max = 0;
     size_t maxIndex = 0;
     vector<size_t> row(b.size() + 1, 0);
     vector< vector<size_t> > dp(a.size() + 1, row);
     for (size_t i = 0; i <= b.size(); ++i)
	  dp[0][i] = 0;
     for (size_t i = 0; i <= a.size(); ++i)
	  dp[i][0] = 0;
     for (size_t i = 1; i <= a.size(); ++i)
	  for (size_t j = 1; j <= b.size(); ++j)
	  {
	       if (a[i-1] == b[j-1])
	       {
		    dp[i][j] = dp[i-1][j-1] + 1;
		    if(dp[i][j] > max)
		    {
			 max = dp[i][j];
			 maxIndex = i - 1;
		    }
	       }
	       else
	       {
		    dp[i][j] = 0;
	       }
	  }
     return a.substr(maxIndex - max + 1, max);
}

int main()
{
     string a("abcdefghijklmn");
     string b("abcfghijkbjf");
     cout << findSubString(a, b) << endl;
}
