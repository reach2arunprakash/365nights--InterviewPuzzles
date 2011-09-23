#include <vector>
#include <iostream>
using namespace std;

template <typename Iterator>
long find(Iterator first, Iterator last)
{
     long checker = 0;
     for (Iterator i = first; i != last; ++i)
	  checker ^= *i;
     return checker;
}

int main()
{
     long a[]={1,2,3,4,5,4,3,2,1};
     vector<long> v(a, a + sizeof(a)/sizeof(long));
     cout << find(v.begin(), v.end()) << endl;
     return 0;
}
