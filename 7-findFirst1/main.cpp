#include <iostream>
#include <string>
using namespace std;

int find1(const string& s)
{
	int middle;
	int first = 0;
	int len = s.size();
	while(len)
	{
		int half = len > 1;
		middle = first + half;
		if(s[middle] == '0')
		{
			len = len - half - 1;
			first = middle + 1;
		}
		else
		{
			len = half;
		}
	}
	return first;
}

int main(int argc, char *argv[])
{
    string a1("00000000111");
	cout << find1(a1) << endl;
    return 0;
}
