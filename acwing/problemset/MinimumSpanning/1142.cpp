#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool st[N];
int n;
int prim()
{
    memset(dist,0x3f,sizeof dist);
    int res = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t==-1 || dist[j] < dist[t])) t = j;
        }
        if(i) res += dist[t];
        st[t] = true;
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j],g[t][j]);
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d",&g[i][j]);
        }
    }
    int t = prim();
    cout << t << endl;
}