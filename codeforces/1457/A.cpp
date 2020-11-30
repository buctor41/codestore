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
int t;
int n,m,r,c;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n >> m >> r >> c;
        int ans = max(r+c-2,r+m-c-1);
        ans = max(ans,n-r+c-1);
        ans = max(ans,n-r+m-c);
        cout << ans << endl;
    }
}