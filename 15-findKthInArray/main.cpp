#include <vector>
#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
     int t = a;
     a = b;
     b = t;
}

template<typename I>
I par(I first, I last)
{
     if (first == last)
	  return last;
     I pivot = last - 1;
     I a = first - 1;
     I b = first;
     while(b != pivot)
     {
	  if(* b > * pivot)
	       ++b;
	  else if (*b <= * pivot)
	  {
	       ++a;
	       swap(*b, *a);
	       ++b;
	  }
     }
     a++;
     swap(*a, *pivot);
     return a;
}

template <typename I>
I findKth(I first, I last, int k)
{
     I m = par (first, last);
     int l = m - first + 1;
     if (l == k)
	  return m;
     if (l < k)
	  return findKth(m + 1, last, k - l);
     if (l > k)
	  return findKth(first, m, k);
}


int main()
{
     int array[] = {5, 3, 4, 2, 1};
     vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
     vector<int>::iterator result;
     result = findKth(v.begin(), v.end(), 5);
     cout << *result << endl;     
}

