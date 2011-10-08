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

bool checkReg(string str, string p)
{
     assert(str.size());
     assert(p.size());     
     int i = 0;
     int j = 0;
     char cur;
     while( i < str.size() && j < p.size())
     {
	  if (p[j] == '*')
	  {
	       while (i != str.size() && match(str[i], cur))
 
		    i++;
	       j += 1;
	  }
	  else if(p[j] == '.')
	  {
	       cur=p[j];
	       ++i;
	       ++j;
	  }	    
	  else if(!match(str[i], p[j]))
	  {
	       if (!(j + 1 < p.size() && p[j + 1] == '*'))
		    return false;
	       else
	       {
		    cur = p[j];
		    ++j;
	       }
	  }
	  else
	  {
	       cur=p[j];
	       ++i;
	       ++j;
	  }
     }

}
if (i < str.size())
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
