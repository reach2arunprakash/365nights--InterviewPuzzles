#include <stack>
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
struct Step
{
     char from;
     char temp;
     char to;
     int n;
};

void Move(char from, char temp, char to, int n)
{
     stack< Step > ss;
     Step s = {from, temp, to, n};
     ss.push(s);
     while(ss.size() > 0)
     {
	  Step intent = ss.top();
	  assert(intent.n != 0);
	  if(intent.n == 1)
	  {
	       cout << "move " << " from " << intent.from << " to " << intent.to << endl;
	       ss.pop();
	       continue;	       
	  }
	  Step step1 = {intent.from, intent.to, intent.temp, intent.n - 1};
	  Step step2 = {intent.from, intent.temp, intent.to, 1};	  
	  Step step3 = {intent.temp, intent.from, intent.to, intent.n - 1};

	  ss.pop();
	  ss.push(step3);
	  ss.push(step2);
	  ss.push(step1);
     }
}

int main()
{
     Move('a', 'b', 'c', 3);
     return 0;
}
