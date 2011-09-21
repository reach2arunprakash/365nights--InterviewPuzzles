#include <list>
#include <iostream>
#include <memory>
#include <assert.h>
using namespace std;
template <typename Iterator>
auto_ptr< list<int> > addList(Iterator start1, Iterator start2, Iterator last1, Iterator last2)
{
	auto_ptr< list<int> > l(new list<int>);
	int carry = 0;
	while(start1 != last1 && start2 != last2)
	{
		int value = *start1 + *start2 + carry;
		assert(value <= 19);
		l->push_back(value % 10);
		carry = value / 10;
		++start1;
		++start2;
	}
	while(start1 != last1)
	{
		int value = *start1 + carry;
		l->push_back(value % 10);
		start1++;
		carry = value / 10;
	}
	while(start2 != last2)
	{
		int value = *start2 + carry;
		l->push_back(value % 10);
		start2++;
		carry = value / 10;
	}
	if(carry)
	{
		assert(carry==1);
		l->push_back(carry);
	}
	return l;
}

int main(int argc, char *argv[])
{
    int a[] = {8,7,3};
	int b[] = {9, 9, 9, 9};

	list< int > l1;
	l1.push_back(8);
	l1.push_back(7);
	l1.push_back(3);	
	list< int > l2;
	l2.push_back(9);
	l2.push_back(9);
	l2.push_back(9);
	l2.push_back(9);	
	auto_ptr< list<int> > result = addList(l1.begin(), l2.begin(), l1.end(), l2.end());
	list<int>::iterator i;
	for (i = result->begin(); i != result->end(); ++i)
	{
		cout << *i;
	}
	cout << endl;
    return 0;
}

