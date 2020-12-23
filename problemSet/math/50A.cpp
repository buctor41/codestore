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

int n,m;
signed main()
{
    fastio;
    cin >> n >> m;
    int ans = 0;
    if(n % 2 == 0 || m % 2 == 0){
        ans = (n * m) / 2;
    }else{
        int a = max(n,m),b = min(n,m);
        ans += ((a - 1) * b / 2);
        ans += (b / 2);
    }
    cout << ans << endl;
}
