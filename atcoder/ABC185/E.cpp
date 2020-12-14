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

const int N = 1010;
int f[N][N];
int a[N],b[N];
int n,m;
signed main()
{
    fastio;   
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    f[0][0] = n + m;
    for(int i = 1; i <= n; i++) f[i][0] = n + m;
    for(int j = 1; j <= m; j++) f[0][j] = n + m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            f[i][j] = min(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j] = min(f[i][j],f[i-1][j-1]-2);
            else f[i][j] = min(f[i][j],f[i-1][j-1]-1);
        }
    }    
    cout << f[n][m] << endl;
}
