#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

bool match(char c, char p)
{
     if (p == '.')
	  return true;
     return p == c;
}

bool checkReg(string str, string pattern)
{
     assert (str.size());
     assert (pattern.size());
     int i = 0;
     int j = 0;
     char cur;
     while (j != pattern.size() && i != str.size())
     {
	  if (pattern[j] == '*' || pattern[j] == '+')
	  {
	       while (i != str.size() && match(str[i], cur))
		    i ++;
	       j ++ ;
	  }
	  else
	  {
	       if (! match(str[i], pattern[j]))
	       {
		    if (j + 1 == pattern.size()|| pattern[j + 1] != '*')
			 return false;
	       }
	       else
	       {
		    i++;
	       }
	       cur = pattern[j];	       	       
	       j ++ ;



	  }
     }
     if (i < str.size() || j < pattern.size())
	  return false;
     return true;
}

int main()
{
     string str = "b";
     string pattern = "a*";
     cout << checkReg(str, pattern) << endl;
     str = "aaa";
     pattern = "a*";
     cout << checkReg(str, pattern) << endl;
     str = "aba";
     pattern = "a*";
     cout << checkReg(str, pattern) << endl;
     str = "aba";
     pattern = ".*";
     cout << checkReg(str, pattern) << endl;       
}
