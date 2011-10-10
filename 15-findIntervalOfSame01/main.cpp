#include <map>
#include <vector>
#include <iostream>
using namespace std;

void PrintAll(vector<int>& v)
{
     vector<int>::iterator i;
     for (i = v.begin(); i != v.end(); ++i)
     {
	  if(*i == 0)
	       *i = -1;
     }
     map<int, vector<int> > hash;
     int sum = 0;
     for (i = v.begin(); i != v.end(); ++i)
     {
	  map<int, vector<int> >::iterator it;
	  it = hash.find(sum);
	  if(it == hash.end())
	  {
	       vector<int> newV;
	       newV.push_back(i - v.begin());
	       hash[sum] = newV; 
	  }
	  else
	  {
	       vector<int>::const_iterator j;
	       for (j = hash[sum].begin(); j != hash[sum].end(); ++j)
		    cout << *j << ' ' << i - v.begin() - 1 << endl; 
	       hash[sum].push_back(i - v.begin());
	  }
	  sum += *i;	  
     }
}

int main()
{
     int array[] = {0,1,0,0,1,1,1,1,0};
     vector<int> v(array, array+sizeof(array)/sizeof(array[0]));
     PrintAll(v);
     return 0;
}
