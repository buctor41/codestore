//https://www.acwing.com/problem/content/852/
//堆优化版本dijkstra
//注意:h数组要初始化
//     dist数组要初始化
//这道题还是不太理解
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e6 + 10;
int h[N],e[N],w[N],ne[N],idx;
int n,m;
void add(int a,int b,int c)
{
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}
int dist[N];
bool st[N];
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,1});
    while(q.size()){
        auto t = q.top();
        q.pop();
        int idx = t.second,distance = t.first;
        if(st[idx]) continue;
        st[idx] = true;
        for(int i = h[idx];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                q.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i = 0,a,b,c; i < m; i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int t = dijkstra();
    cout << t << endl;
}