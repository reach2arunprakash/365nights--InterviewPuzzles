#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool findNextPermutation(string& s)
{
     string::iterator i, j, k;
     i = s.begin() + 1;
     j = s.begin();
     while(i != s.end())
     {
	  if (*i == '0' && *j == '1')
	  {
	       k = s.begin();
	       while(*k != '1')
		    ++k;
	       *k = '0';
	       *i = '1';
	       reverse(s.begin(), i);
	       return true;
	  }
	  ++i, ++j;
     }
     return false;
}

void printSubSet(const vector<int>& v, int k)
{
     string bits;
     for(int i = 0; i < v.size(); ++i)
	  if ( i < k)
	       bits.push_back('1');
	  else
	       bits.push_back('0');
     do
     {
	  for (int i = 0; i < bits.size(); ++i)
	       if (bits[i] == '1')
		    cout << v[i] << ' ';
	  cout << endl;
     }while(findNextPermutation(bits));
}

int main()
{
     int array[] = {1, 2, 3, 4, 5};
     vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
     printSubSet(v, 3);
}
