#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;

double Sqrt(double d)
{
     assert (d >= 0);
     const static double eps = 0.000001f;
     
     double min = 0.0f;
     double max = d;

     double middle = (min + max) / 2.0f;

     while(abs(middle * middle - d) > eps)
     {
	  if (middle * middle > d)
	       max = middle;
	  else
	       min = middle;
	  middle = (max + min) / 2.0f;
     }
     
     return middle;
}

int main()
{
     double v = 3;
     cout << Sqrt(3) << endl;
     cout << sqrt(3) << endl;
}
