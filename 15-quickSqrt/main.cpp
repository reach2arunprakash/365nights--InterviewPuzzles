#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;

double Sqrt(double d)
{
     assert (d > 0);
     static const double esp = 0.00001f;
     double x = d ;
     while (abs(x * x - d) > esp)
     	  x = (x + d / x) / 2;
     return x;
}


int main()
{
     cout << sqrt(0.3f) << endl;
     cout << Sqrt(0.3f) << endl;
     return 0;
}
