#include <string>
#include <iostream>
using namespace std;

bool isRotation(string str1, string str2)
{
     if (str1.length()!=str2.length())
	  return false;
     str1 += str1;

     size_t found = str1.find(str2);
     return (found != string::npos);
	  
}

int main()
{
     cout << isRotation(string("apple"), string("pleap")) << endl;
     cout << isRotation(string("apple"), string("pear")) << endl;
     cout << isRotation(string(""), string("")) << endl;
     cout << isRotation(string("apple"), string("wrong")) << endl;
}
