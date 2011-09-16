#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


void replaceString(string& str)
{
     string::iterator i;
     int count = 0;
     int end = str.length() - 1;
     for (i = str.begin(); i != str.end(); ++i)
     {
	  if(*i == ' ')
	       count += 3;
	  else
	       count ++;
     }

     str.resize(count);
     count--;
     while(end>=0)
     {
	  if(str[end]!=' ')
	       str[count--] = str[end];
	  else
	  {
	       str[count--] = '0';
	       str[count--] = '2';
	       str[count--] = '%';	       
	  }
	  end--;
     }
     assert(end == count);
}

int main()
{
     string str1="";
     string str2="wa wa wa ";
     string str3="         ";
     string str4="nospace";
     replaceString(str1);
     replaceString(str2);
     replaceString(str3);
     replaceString(str4);
     cout << str1 << endl;
     cout << str2 << endl;
     cout << str3 << endl;
     cout << str4 << endl;     
}
