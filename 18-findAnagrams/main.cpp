#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


vector< vector< string > > findAnagrams(const vector< string >& v)
{
     map< string, vector< string > > m;

     for (int i = 0; i < v.size(); ++i)
     {
	  string key = v[i];

	  sort(key.begin(), key.end());

	  m[key].push_back(v[i]);
     }
     vector < vector <string> > r;
     map<string, vector< string > >::iterator i ;

     for ( i = m.begin(); i != m.end(); ++i)
	  r.push_back(i->second);
     return r;     
}


int main()
{
     string a("abc");
     string b("cba");
     string c("def");
     string d("fed");
     vector< string > v;
     v.push_back(a);
     v.push_back(b);
     v.push_back(c);
     v.push_back(d);
     vector< vector< string > > r = findAnagrams(v);
     for (int i = 0; i < r.size(); ++i)
     {
	  for (int j = 0; j < r[i].size(); ++j)
	       cout << r[i][j] << ' ';
	  cout << endl;
     }
}
