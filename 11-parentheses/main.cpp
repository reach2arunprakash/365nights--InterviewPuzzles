#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printParenthese(int l, int r, string s)
{
     if(r == 0 && l == 0)
     {
	  cout << s << endl;
	  return;
     }
     if(l < 0)
	  return;
     if(l == r)
     {
	  printParenthese(l - 1, r, s + '(');
     }
     if(l < r)
     {
	  printParenthese(l - 1, r, s + '(');
	  printParenthese(l , r - 1, s + ')');	  	  
     }

}
int main()
{
     printParenthese(3, 3, "");
}
