#include <iostream>
#include <string>
using namespace std;

bool isUniqString(const string& s)
{
	 int checker[4] = {0, 0, 0, 0};
	 string::const_iterator i;
	 for (i = s.begin(); i != s.end(); ++i)
	 {
		  int c = (int)*i;
		  int index = c / 32;
		  int pos = 1 << (c % 32);
		  if (checker[index] & pos)
			   return false;
		  checker[index] |= pos;
	 }
	 return true;
}

int main(int argc, char *argv[])
{
	 string a = "asdfghjkl";
	 string b = "aaabbb";
	 string c = "";
	 string d = "abca";
	 cout << isUniqString(a) <<" "
		  << isUniqString(b) <<" "
		  << isUniqString(c) <<" "
		  << isUniqString(d) <<" "
		  <<endl;
	 return 0;
}

