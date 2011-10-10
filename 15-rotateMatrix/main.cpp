#include <iostream>
using namespace std;

void Rotate(int src[5][5], int n)
{
     for (int i = 0; i < n / 2; ++i)
	  for (int j = i; j < n - 1 - i; ++ j)
	  {
	       int temp = src [i][j];
	       src[i][j] = src[j][n - 1 - i];
	       src[j][n - 1 - i] = src[n - 1 - i][n - 1 - j];
	       src[n - 1 - i][n - 1 - j] = src[n - 1 - j][i];
	       src[n - 1 - j][i] = temp;
	  }
}

int main()
{
     int src[5][5] = {{1,2,3,4,5},
		    {6,7,8,9,10},
		    {11,12,13,14,15},
		    {16,17,18,19,20},
		    {21,22,23,24,25}};
     for (int i = 0; i < 5; ++i)
     {
	  for (int j = 0; j < 5; ++j)
	       cout << src[i][j] << ' ';
	  cout << endl;
     }
     cout << endl;
     Rotate(src, 5);
     for (int i = 0; i < 5; ++i)
     {
	  for (int j = 0; j < 5; ++j)
	       cout << src[i][j] << ' ';
	  cout << endl;
     }     
}
