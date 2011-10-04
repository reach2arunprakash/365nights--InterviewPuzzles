#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
		
string findLongest(const string& s1, const string& s2)
{
	if(0 == s1.size() || 0 == s2.size()) 
		return "";
	vector<int> row(s2.size() + 1) ;
	vector< vector<int> > dp(s1.size() + 1, row);
	for(int i = 0; i < s1.size() + 1; ++i)
		dp[i][0] = 0;
	for(int i = 0; i < s2.size() + 1; ++i)
		dp[0][i] = 0;

	for(int i = 1; i < s1.size() + 1; ++i)
		for (int j = 1; j < s2.size() + 1; ++j)
			if(s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	string result;
	int i = s1.size();
	int j = s2.size();
	while(i > 0 && j > 0)
	{
		if(dp[i][j] > dp[i][j - 1] && dp[i][j] > dp[i - 1][j])
		{
			result.push_back(s1[i - 1]);
			i--, j--;
			continue;
		}

		if(dp[i][j - 1] > dp[i - 1][j])
		{
			j--;
			continue;
		}else{
			i--;
			continue;
		}
	}
	return result;
	
}

int main()
{
	string a = "bdcaba";
	string b = "abcbdab";
	cout << findLongest(a, b) << endl;
	return 0;
}
	
