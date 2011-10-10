#include <iostream>
#include <assert.h>
#include <vector>
#include <stack>
using namespace std;

int maxArea(const vector<int>& v)
{
     assert(v.size());
     stack<int> s;
     int maxArea = -1;
     for (int i = 0; i < v.size(); ++i)
     {
	  while(s.size() && v[i] < v[s.top()])
	  {
	       int top = s.top();
	       s.pop();	       
	       int next = s.size() ? s.top() : -1;
	       int area = (top - next) * v[top];
	       maxArea = max(area, maxArea);
	  }
	  s.push(i);
     }
     while (s.size() > 1)
     {
	  int top = s.top();
	  s.pop();	       
	  int next = s.size() ? s.top() : -1;
	  int area = (top - next) * v[top];
	  maxArea = max(area, maxArea);	  
     }

     int area = v[s.top()] * v.size();
     maxArea = max(area, maxArea);
     return maxArea;
}

int main()
{
     int array[] = {9, 6, 2, 1, 3, 5, 4, 8, 2, 7};
     vector<int> v (array, array + sizeof(array) / sizeof(array[0]));
     cout << maxArea(v) << endl;
}
