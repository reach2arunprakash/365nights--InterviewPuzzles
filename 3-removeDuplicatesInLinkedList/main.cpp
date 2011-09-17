#include <list>
#include <iostream>
using namespace std;

template < typename T >
void removeDuplicate(list<T>& l)
{
     typename list<T>::iterator i;
     typename list<T>::iterator j;
     for (i = l.begin(); i != l.end(); ++i)
     {
	  j = i;
	  while(j != l.end())
	  {
	       if(j == i)
	       {
		    ++j;
		    continue;
	       }
	       if(*j == *i)
		    l.erase(j++);
	       else
		    ++j;
	  }
     }
}

int main()
{
     int array[] = {1, 2, 3, 4, 5, 6, 1, 2,3 ,4, 5, 1, 2, 3, 4,5};
     list<int> a;
     for (int i = 0; i < 16 ; i++)
	  a.push_back(array[i]);

     removeDuplicate< int >(a);
     list<int>::iterator i;
     for (i = a.begin(); i != a.end(); ++i)
	  cout << *i;
     cout << endl;
}
