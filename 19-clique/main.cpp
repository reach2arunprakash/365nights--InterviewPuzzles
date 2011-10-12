#include <stdio.h>


int getMax(int n, int m)
{
     int t = n / m;
     int k = n - t * m;
     int total = 0;
     total += (t + 1) * (t + 1) * (k - 1) * (k) / 2;
     total += (t + 1 ) * t * (m - k) * k;
     total += t * t * (m - k) * (m - k - 1) / 2;
     return total;
}

int main()
{
     int t;
     scanf("%d", &t);
     while(t--)
     {
	  int  n, m;
	  scanf("%d %d", &n, &m);
	  int  i = 2;
	  int  v;
	  while(1)
	  {
	       //if (dp[n][i] != 0)
//		    v = dp[n][i];
//	       else
//	       {
	       v = getMax(n, i);
//		    dp[n][i] = v;
//	       }
	       if (v >= m)
		    break;
	       ++i;
	  }
	  printf("%d", i);
	  if(t)
	       printf("\n", i);
     }
     return 0;
}
