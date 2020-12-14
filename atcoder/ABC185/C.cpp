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
int c[220][15];
int n;
signed main()
{
    fastio;   
    cin >> n;
    int 
    return 0;
}

//c[n-1][11]
//c[i][j]从i中选11个的可能数
//c[0][0] = 1;
//c[1][0] = 1;
//c[1][1] = c[0][1] + c[0][0]
//c[2][0] = 1
//c[2][1] = c[1][1] + c[1][0] 
//c[2][2] = 1
//c[3][1] = c[2][1] + c[2][0]
//c[3][2] = c[2][2] + c[2][1]
//