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
const int N = 110;
int a[N];
int t,n,m;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(a,0,sizeof(a));
        for(int i = 0,v;i < n; i++){
            cin >> v;
            a[v]++;
        }
        for(int i = 0,v; i < m; i++){
            cin >> v;
            a[v]++;
        }
        int ans = 0;
        for(int i = 1; i  <= 100; i++) {
            if(a[i] >= 2) ans++;
        }
        cout << ans << endl;
    }   
    return 0;
}