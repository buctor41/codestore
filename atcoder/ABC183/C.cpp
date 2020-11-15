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

const int N = 10;
int g[N][N];
int st[N];
int n,T;
int res;
void dfs(int u,int step,int c)
{
    if(step==n-1){
        if(c+g[u][1]==T) res++;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            if(c+g[u][i] < T){
                st[i] = 1;
                dfs(i,step+1,c+g[u][i]);
                st[i] = 0;
            }
        }
    }
}
signed main()
{
    fastio;
    cin >> n >> T;
    memset(st,0,sizeof(st));
    for(int i = 1; i <=  n; i++)
        for(int j = 1; j <= n; j++) cin >> g[i][j];
    st[1] = 1;
    dfs(1,0,0);
    cout << res <<endl;
}
