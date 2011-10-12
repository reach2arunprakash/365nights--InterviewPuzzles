#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

string mapping[] = { "ABC", "DEF", "GHI", "JKL", "MNO",
		   "PQR", "STU", "VW", "XY", "Z*#" };
void printAll(char* str, string s)
{
     if (*str == '\0')
     {
	  cout << s << endl;
	  return ;
     }

     int n = *str - '0' - 1;
     assert( n >= 0 && n < 9);

     for (int i = 0; i < mapping [n].size(); ++i)
     {
	  string newString = s;
	  newString.push_back(mapping[n][i]);
	  printAll(str + 1, newString);
     }
}

int main()
{
     string s;
     printAll("1234", s);
}
