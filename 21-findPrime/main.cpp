#include <iostream>
using namespace std;

bool dp[10001];

void findPrime()
{
	for (int i = 0; i <= 10000; ++i)
		dp[i] = true;
	
	for (int i = 2; i <= 10000; ++i)
	{
		if (!dp[i])
			continue;
		for (int j = i + i; j <= 10000; j += i)
			dp[j] = false;
	}
}

int main()
{
	findPrime();
	for (int i = 0; i < 10001; ++i)
		if (dp[i])
			cout << i << endl;
}
	
