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
int n;
signed main()
{    
    int n;
    cin >> n;
    int l = 1,r = 1e10,t = (n+1) * 2;
    while(l < r){
        int mid = l + r + 1>> 1;
        if(mid*(mid+1) <= t) l = mid;
        else r = mid - 1;
    }
    int res = n - l + 1;
    cout << res << endl;
}