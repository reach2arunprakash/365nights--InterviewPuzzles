#include <vector>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <iomanip>
using namespace std;

void rotate(vector <vector<int> >& src)
{
     assert(src.size());
     assert(src[0].size());
     int sizeC = src.size();
     int sizeR = src[0].size();

     int size = sizeC > sizeR ? sizeC : sizeR;
     src.resize(size);     
     for (int i = 0; i < size; ++i)
	  src[i].resize(size);
     
     for (int i = 0; i < sizeC; ++i)
	  for (int j = i; j< sizeR; ++j)
	       swap(src[i][j], src[j][i]);

     for (int i = 0; i < sizeR; ++i)
	  for (int j = 0; j < sizeC / 2; ++j)
	       swap(src[i][j], src[i][sizeC - 1 - j]);
     src.resize(sizeR);
     for (int i = 0; i < sizeR; ++i)
	  src[i].resize(sizeC);     
}

int main()
{
     vector<vector<int> >v;
     int count = 1;
     for (int i = 0; i < 5; i++)
     {
	  vector <int >row;
	  v.push_back(row);
	  for (int j = 0; j < 10; j++)
	       v[i].push_back(count++);
     }
     for (int i = 0; i < v.size(); i++)
     {
	  for (int j = 0; j < v[0].size(); j++)
	       cout <<' ' << setw(2) << v[i][j];
	  cout << endl;	  
     }
     cout << endl;
     rotate(v);

     for (int i = 0; i < v.size(); i++)
     {
	  for (int j = 0; j < v[0].size(); j++)
	       cout <<' ' << setw(2) << v[i][j];
	  cout << endl;	  
     }     
}
