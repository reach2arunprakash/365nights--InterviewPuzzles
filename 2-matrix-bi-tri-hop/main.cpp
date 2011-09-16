#include <iostream>
using namespace std;

#define N 7
int a[N][N] = {{1,1,0,0,0,0,1},
	       {1,1,1,1,0,0,0},
	       {0,1,1,1,0,0,0},
	       {0,1,1,1,1,0,0},
	       {0,0,0,1,1,1,0},
	       {0,0,0,0,1,1,1},
	       {1,0,0,0,0,1,1}};

void printMatrix()
{
     for(int i = 0; i < N; ++i)
     {
	  for(int j = 0; j < N; ++j)
	  {
	       cout << a[i][j];
	  }
	  cout << endl;
     }
}

void floyd_marshall(int K)
{
     for (int i = 0; i < K; ++i)
     {
	  bool b[N][N];
	  for(int j = 0; j < N; ++j)
	       for(int k = 0; k < N; ++k)
		    b[j][k] = a[j][k];
	  for(int j = 0; j < N; ++j)
	  {
	       for(int k = 0; k < N; ++k)
	       {
		    if(b[j][k])
			 for(int l = 0; l < N; ++l)
			 {
			      if(l == j)
				   continue;
			      if(b[k][l])
				   a[j][l] = 1;
			 }
	       }
	  }
     }
}




int main()
{
     floyd_marshall(1);
     printMatrix();
}
