//https://www.acwing.com/problem/content/851/
//朴素dijkstra
//时间复杂度O(N^2),空间复杂度O(N^2)
//存储方式:邻接矩阵

//算法流程:
//初始化:dist[1] = 0, dist[i] = INF 
//s集合初始化为0
//进行n次迭代：
//      1.找到1-n中不属于s集合的点且dist[i]最小
//      2.将这个点加入s集合
//      3.用这个点t，更新所有点:dist[j] = min(dist[j],dist[t]+g[t][j]) 
#include <bits/stdc++.h>
using namespace std;
const int N = 550;
int g[N][N];
int dist[N];
bool s[N];
int n,m;
void dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 1; i < n; i++)
    {
        int idx = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!s[j] && (idx==-1 || dist[j] < dist[idx])) idx = j;
        }
        s[idx] = true;
        for(int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j],dist[idx]+g[idx][j]);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = min(g[a][b],c);   //重边
    }
    dijkstra();
    if(dist[n]==0x3f3f3f3f) cout << "-1" << endl;
    else cout << dist[n] << endl;
    return 0;
}