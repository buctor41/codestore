#include <bits/stdc++.h>
using namespace std;
const int N = 550,INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool st[N];
int n,m;
//n次迭代，每次寻找到不在s集合中且dist[t]最小的t
//第0次迭代不需要更新res
//以后的迭代需要判断dist[t]是否为INF，如果是INF则直接返回
//不是的话则继续走，并且将dist[t]加入res
//然后用t，更新其他点更新方程为dist[j] = min(dist[j],g[t][j])
//与dijkstra不同的是,dist[j]表达的是该点到s集合的距离，不是到点1的距离
int prim()
{
    memset(dist,0x3f,sizeof dist);
    int res = 0;
    for(int i = 0; i < n; i++){
        int t = - 1;
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t==-1 || dist[j] < dist[t])) t = j;
        }
        if(i&&dist[t]==INF) return INF;
        if(i) res += dist[t];
        st[t] = true;
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j],g[t][j]);
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    for(int i = 0,a,b,c; i < m; i++){
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = g[b][a] = min(g[b][a],c);
    }
    int t = prim();
    if(t==INF) puts("impossible");
    else cout << t << endl;
    return 0;
}