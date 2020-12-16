#include <bits/stdc++.h>
using namespace std;

int check(double x)
{
    double y = x + 2 * x * x * x;
    if(y >= 1000000) return 1;
    else return 0;
}
signed main()
{
      //x + 2 * x ^ 3 = 1000000   ºóËÄÎ»i
      double eps = 1e-6;
      double l = 0,r = 1e6;
      while(l + eps < r)
      {
          double mid = (l + r) / 2;
          if(check(mid)) r = mid;
          else l = mid;
      }
      printf("%.4lf\n",l);
}
