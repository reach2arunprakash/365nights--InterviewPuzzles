#include <string>
#include <iostream>
using namespace std;

bool anagram(string s1, string s2)
{
     int count[256] = {0};
     string::iterator i;
     for (i = s1.begin(); i != s1.end(); ++i)
     {
	  count[*i]++;
     }
     for (i = s2.begin(); i != s2.end(); ++i)
     {
	  count[*i]--;
     }
     for (int i = 0; i < 256; ++i)
     {
	  if(count[i])
	       return false;
     }
     return true;
}


int main()
{
     string str1("anagram");
     string str2("aangram");
     string str3("123");
     string str4("aaangrm");
     cout << anagram(str1, str2) << endl;
     cout << anagram(str2, str3) << endl;
     cout << anagram(str2, str4) << endl;     
}
  
