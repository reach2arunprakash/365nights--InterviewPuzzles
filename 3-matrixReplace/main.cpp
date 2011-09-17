#include <iostream>
using namespace std;

#define M 3
#define N 7

int a[M][N] = {{1,2,3,4,5,6,0},
	       {3,1,2,3,4,5,6},
	       {0,2,2,0,4,5,6}};

void matrixReplace()
{
     int b[M][N];
     for (int i = 0; i < M; i++)
	  for (int j = 0; j < N; ++j)
	       b[i][j] = a[i][j];

     for (int i = 0; i < M; i++)
	  for (int j = 0; j < N; ++j)
	  {
	       if (a[i][j] == 0)
	       {
		    for(int k = 0; k < M; ++k)
			 b[k][j] = 0;
		    for(int k = 0; k < N; ++k)
			 b[i][k] = 0;
	       }
	  }
     for (int i = 0; i < M; i++)
	  for (int j = 0; j < N; ++j)
	  {
	       if(b[i][j] == 0)
		    a[i][j] = 0;
	  }
}

int main()
{
     matrixReplace();
     for (int i = 0; i < M; i++)
     {
	  for (int j = 0; j < N; ++j)
	       cout << a[i][j];
	  cout << endl;
     }
}
