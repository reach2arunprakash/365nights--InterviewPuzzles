#include <string>
#include <iostream>
using namespace std;

void removeDuplicates(string& s)
{
     bool prev = false;
     size_t a = 0;
     size_t b = 0;

     while(b != s.size())
     {
	  if (s[b] == '/' && prev)
	       b++;
	  else
	  {
	       prev = (s[b] == '/');
	       s[a++] = s[b++];
	  }
     }
     s.resize(a);
}

int main()
{
     string a = "//root//foo/bar//";
     removeDuplicates(a);
     cout << a << endl;
}
