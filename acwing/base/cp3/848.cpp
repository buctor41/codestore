#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10,M = 2 * N;
int h[N],e[M],ne[M],idx;
void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
int n,m;
int path[N];
int d[N];//记录入度
int bfs()
{
    queue<int> q;
    //预处理
    for(int i = 1; i <= n; i++){
        if(d[i]==0) q.push(i);
    }
    int cnt = 0;
    while(q.size())
    {
        int t = q.front();
        q.pop();
        path[cnt++] = t;
        
        for(int i = h[t];i != -1; i=ne[i]){
            int j = e[i];
            d[j]--;
            if(d[j]==0){
                q.push(j);
            }
        }
    }
    return cnt;
}
int main()
{
    memset(h,-1,sizeof h);
    cin >> n >> m;
    for(int i = 0,a,b;i < m; i++)
    {
        cin >> a >> b;
        d[b]++;
        add(a,b);
    }
    int v = bfs();
    if(v!=n){
        cout << -1;
    }else{
        for(int i = 0; i < n; i++){
            cout << path[i] << " ";
        }
    }
    puts("");
    return 0;
}