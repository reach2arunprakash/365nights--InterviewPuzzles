#include <stack>
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
	stack<T> regular;
	stack<T> min;
public:
    void pop()
		{
			if (regular.top() == min.top())
			{
				min.pop();
			}
			regular.pop();
		}
	void push(const T& value)
		{
			if(min.size() == 0)
				min.push(value);
			else
				if(value <= min.top())
					min.push(value);
			regular.push(value);
		}
	T& top()
		{
			return regular.top();
		}
	
	T& getMin()
		{
			return min.top();
		}
};

int main()
{
	Stack<int> s;
	s.push(2);
	cout << s.getMin() <<endl;
	s.push(2);
	cout << s.getMin() <<endl;
	s.push(3);
	cout << s.getMin() <<endl;
	s.pop();
	cout << s.getMin() <<endl;
	s.pop();
	cout << s.getMin() <<endl;	
}
