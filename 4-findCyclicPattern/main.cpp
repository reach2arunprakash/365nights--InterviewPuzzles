#include <string>
#include <iostream>
using namespace std;

string isRepeated(string word)
{
    int N = word.length();
    int i = 0;
    while(++i <= N/2)
    {
        if (N % i == 0)
		{
			string pattern = word.substr(0,i);
			int j = i;
			for(; j < N; j+=i)
			{
				if(word.substr(j,i) != pattern)
					break;
			}
			if (j == N)
				return pattern;
		}
	}
	return "";
}

int main(int argc, char *argv[])
{
	cout << isRepeated("abababab") << endl;
	cout << isRepeated("aabaab") << endl;
	cout << isRepeated("aabdaab") << endl;
	cout << isRepeated("aaaaaaa") << endl;
	cout << isRepeated("abcdabcd") << endl;	
    return 0;
}
