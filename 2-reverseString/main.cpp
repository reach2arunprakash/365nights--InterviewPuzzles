#include <iostream>
using namespace std;

char* reverse(char *str)
{
	 int end = 0;
	 while(str[end])
		  end++;
	 end--;
	 int i = 0;
	 while(i < end)
	 {
		  char temp;
		  temp = str[i];
		  str[i] = str[end];
		  str[end] = temp;
		  i++;
		  end--;
	 }
	 return str;
}

int main(int argc, char *argv[])
{
	 char str1[] = "abcd";
	 char str2[] = "abc";
	 char str3[] = "";
	 cout << reverse(str1) << endl;
	 cout << reverse(str2) << endl;
	 cout << reverse(str3) << endl;
	 return 0;
}
