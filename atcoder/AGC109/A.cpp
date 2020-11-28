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

#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

signed main()
{
    fastio;
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    int ans;
    if(a==b){
        ans = x;
    }else if(a > b){
        int t = a - b - 1;
        ans = x + min(y,2*x) * t;
    }else{
        int t = b - a;
        ans = x + min(y,2*x) * t;
    }
    cout << ans << endl;
}