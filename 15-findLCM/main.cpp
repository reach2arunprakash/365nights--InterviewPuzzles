#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
     if(a < b)
	  swap (a, b);
     int c = a % b;
     while(c)
     {
	  a = b;
	  b = c;
	  c = a % b;
     }
     return b;
}

int commonGCD(const vector<int>& v)
{
     int GCD = v[0];
     for (int i = 1; i < v.size(); ++i)
	  GCD = gcd(v[i], GCD);
     return GCD;
}

int LCM(const vector<int>& v)
{
     int result = 1;
     for (int i = 0; i < v.size(); ++i)
	  result = (result / gcd(result, v[i]) * v[i]);
     return result;
}

int main()
{
     int array[] = {2, 3, 5};
     vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
     cout << LCM(v) << endl;
}


