#include <iostream>
using namespace std;

int countWords(char* str)
{
     int i = 0;
     while(str[i] && str[i] == ' ')
	  i++;
     if (!str[i])
	  return 0;
     while(str[i] && str[i] != ' ')
	  i++;
     if (!str[i])
	  return 1;     
     return countWords(str + i) + 1;
}

int main()
{
     char* str = "   wo   zhen  shi   ge     huai  dan    ";
     cout << countWords(str) << endl;
     return 0;
}
