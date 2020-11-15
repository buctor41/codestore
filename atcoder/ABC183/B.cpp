#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define int ll

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())


signed main()
{
    double sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    double st = abs(gx-sx);
    if(sx==gx) cout <<sx << endl;
    else if(sx > gx){
      double per = (sy) / (gy+sy);
      double res = sx - per * st;
      printf("%f",res);
    }else{
      double per = (sy) / (gy+sy);
      double res = st * per + sx;
      printf("%f",res);
    }

}
