#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
using namespace std;


struct Task
{
     int d;
     int m;
};

bool compare(const Task &a,const Task &b)
{
     return a.d < b.d;	
}
struct cmp
{
     bool operator()(const Task &a,const Task &b)
	  {
	       return a.d > b.d;	
	  }
};
typedef list<Task>::const_iterator I;
typedef vector<Task, allocator<Task> > TASKDQU;
typedef priority_queue<Task,TASKDQU, cmp> TASKPRQUE;

int getMin(TASKPRQUE tq)
{
     int time = 0;
     I i;
     int max = 0;
     while(tq.size() > 0)
     {
	  Task node;
	  Task t = tq.top();
	  node.d = t.d;
	  node.m = t.m;
	  tq.pop();
	  time += node.m;
	  if(time >= node.d)
	       if(max < time - node.d)
		    max = time - node.d;
     }
     return max;
}

int main(int argc, char *argv[])
{
     int n;
     cin >> n;
     TASKPRQUE tq;
     while(n--)
     {
	  Task t;
	  cin >> t.d;
	  cin >> t.m;
	  tq.push(t);
	  cout << getMin(tq) << endl;
     }
     return 0;
}
