#include <iostream>
#include <string>
using namespace std;

#define charSetSize (256)

string removeDuplicates(const string& origin)
{
	 string str = origin;
	 bool checker[charSetSize];
	 for (int i = 0; i < charSetSize; ++i)
	 {
		  checker[i] = false;
	 }

	 int end = 0;
	 string::iterator i;
	 for (i = str.begin(); i != str.end(); ++i)
	 {
		  if(!checker[*i])
		  {
			   checker[*i] = true;
			   str[end] = *i;
			   ++end;
		  }
	 }
	 str.resize(end);
	 return str;
}

int main(int argc, char *argv[])
{
	 cout << removeDuplicates("aaabbb") << endl;
	 cout << removeDuplicates("ababab") << endl;
	 cout << removeDuplicates("") << endl;
	 cout << removeDuplicates("123") << endl;
	 return 0;
}
