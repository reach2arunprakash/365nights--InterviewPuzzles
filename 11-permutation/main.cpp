#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string nextPermutation(string s)
{
     if (s.size() <= 1)
	  return s;
     string::reverse_iterator i;
     string::reverse_iterator j;     
     for (j = s.rbegin(), i = s.rbegin() + 1; i != s.rend(); ++i, ++j)
     {
	  if (*i < *j)
	       break;
     }
     if (i == s.rend())
     {
	  reverse(s.begin(), s.end());
	  return s;
     }
     for (j = s.rbegin(); ; ++j)
     {
	  if(*i < *j)
	       break;
     }

     swap(*j, *i);
     reverse(i--, s.rbegin() - 1);
     return s;
}

int main()
{
     string a("12345");
     while(true)
     {
	  a = nextPermutation(a);
	  cout << a << endl;
     }
}
