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

int n,m,x;
signed main()
{
    fastio;
    cin >> n >> m >> x;
    x -= 1;
    n -= 2 * x; m -= 2 * x;
    int ans;
    if(n <= 0 || m <= 0){
        ans = 0;
    }else if(n == 1 && m == 1){
        ans = 1;
    }else if(n == 1){
        ans = (m + 1) / 2;
    }else if(m == 1){
        ans = (n + 1) / 2;
    }else{
        ans = n + m - 2;
    }
    cout << ans << endl;
}
