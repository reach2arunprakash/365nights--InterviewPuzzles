#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


struct Task
{
	int d;
	int m;
};

struct cmp
{
	bool operator()(const Task &a,const Task &b)
		{
			return a.d < b.d;	
		}
};
typedef vector<Task>::iterator I;
typedef deque<Task, allocator<Task> > TASKDQU;
typedef priority_queue<Task,TASKDQU, cmp> TASKPRQUE;

int getMin(I first, I last)
{
	int time = 1;
	I i;
	TASKPRQUE tq;
	for (i = first; i != last; ++i)
	{
		tq.push(*i);
	}
	int max = 0;
	while(tq.size() != 0)
	{

		Task t = tq.top();
		Task node;
		node.d = t.d;
		node.m = t.m;
		(node.m)--;
		tq.pop();
		if (node.m != 0)
			tq.push(node);
		else
			if(time >= node.d)
				if(max < time - node.d)
					max = time - node.d;
		++time;
	}
	return max;
}

int main(int argc, char *argv[])
{
    int n;
	cin >> n;
	vector<Task> v;
	while(n--)
	{
		Task t;
		cin >> t.d;
		cin >> t.m;
		v.push_back(t);
		vector<Task> cp(v.begin(), v.end());
		cout << getMin(cp.begin(), cp.end()) << endl;
	}
    return 0;
}
