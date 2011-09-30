#include <set>
#include <iostream>
using namespace std;

set<int> getAll(const set<int> & now, const set<int>& all)
{
     size_t count = 0;
     set<int>::const_iterator i;
     set<int>::const_iterator j;     
     for (i = now.begin(); i != now.end(); ++i)
	  for (j = all.begin(); j != all.end(); ++j)
	       if (*j == *i)
		    count |= ( 1 << (distance(all.begin(), j)));
     ++count;
     count %= (1 << (all.size()));

     set<int> result;
     
     //check one by one
     size_t check = 0;
     while(check < all.size())
     {
	  set<int>::const_iterator i;
	  if(count & (1 << check))
	  {
	       i = all.begin();
	       advance(i, check);
	       result.insert(*i);	       
	  }

	  ++check;
     }
     return result;
}

int main()
{
     set<int> all;
     all.insert(1);
     all.insert(2);
     all.insert(3);

     set<int> subset;
     while(true)
     {
	  subset = getAll(subset, all);
	  set<int>::const_iterator i;
	  for (i = subset.begin(); i != subset.end(); ++i)
	       cout << *i << " ";
	  cout << endl;
     }
     
     return 0;
}
