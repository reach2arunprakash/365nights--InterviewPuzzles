#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

void shuffleArray(int * a, int n)
{
     int i = 1;
     while (i < n)
     {
	  int p = rand() % i;
	  swap(a[p], a[i++]);
     }
}


int main()
{
     int array[] = {1, 2, 3, 4, 5};
     shuffleArray(array, 5);
     for (int i = 0; i < 5; i ++)
     {
	  cout << array[i] << endl;
     }
}
