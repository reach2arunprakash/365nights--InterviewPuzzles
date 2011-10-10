#include <iostream>
#include <string>
#include <vector>
using namespace std;

int KMP (string str, string p, vector<int> next)
{
     int j = -1;
     for (int i = 0; i < str.size(); ++i)
     {
	  while(j >= 0 && str[i] != p[j + 1])
	       j = next[j];
	  if (str[i] == p[j + 1])
	       ++j;
	  if (j == p.size() - 1)
	       return i - p.size();
     }
     return -1;
}

vector<int> getNext(string p)
{
     vector<int> v(p.size());
     int j = -1;
     v[0] = -1;
     for(int i = 1; i < p.size(); ++i)
     {
	  while(j >= 0 && p[j + 1] != p[i])
	       j = v[j];
	  if (p[i] == p[j + 1])
	       ++j;
	  v[i] = j;
     }
     return v;
}

char* strstr(char* haystack, char* needle)
{
     string str(haystack);
     string pattern(needle);

     vector<int> next = getNext(pattern);
     int r = KMP(str, pattern, next);
     if (r == -1)
	  return 0;
     return haystack + r;
}

int main()
{
     char* h = "asdfasdf";
     char* n = "fasd";
     cout << strstr(h, n) << endl;
}
