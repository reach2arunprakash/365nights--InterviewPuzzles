#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;



bool anagramSort(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a < b;
}

int main(int argc, char *argv[])
{
	vector<string> v;
    string s = "hello";
	v.push_back(s);
	s = "fasd";
	v.push_back(s);
	s = "olleh";
	v.push_back(s);
	sort(v.begin(), v.end(), anagramSort);

	vector<string>::iterator i;
	for (i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << endl;
	}
    return 0;
}
