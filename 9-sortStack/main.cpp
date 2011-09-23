#include <stack>
#include <iostream>
using namespace std;

template <typename T>
void sortStack(stack<T>& a1, stack<T>& a2)
{
	T tmp;
	a2.push(a1.top());
	a1.pop();
	while (a1.size() > 0)
	{
		if(a2.top() > a1.top())
		{
			tmp = a1.top();
			a1.pop();
			while(a2.size() > 0 && a2.top() > tmp)
			{
				a1.push(a2.top());
				a2.pop();
			}
			a2.push(tmp);
		}
		else
		{
			a2.push(a1.top());
			a1.pop();
		}
	}
}

int main(int argc, char *argv[])
{
    stack<int> a1;
	stack<int> a2;

	a1.push(0);
	a1.push(1);
	a1.push(5);
	a1.push(3);
	a1.push(4);

	sortStack(a1,a2);
	while(a2.size() > 0)
	{
		cout << a2.top() << endl;
		a2.pop();
	}
    return 0;
}
