#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10,M = 2*N;
int h[N],e[M],ne[M],idx;
void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
int n,m;
bool st[N];
int d[N];
int bfs()
{
    queue<int> q;
    q.push(1);
    d[1] = 0;
    st[1] = true;
    while(q.size()){
        int t = q.front();
        q.pop();
        if(t==n) return d[t];
        for(int i = h[t];i!=-1;i=ne[i])
        {
            int j = e[i];
            if(st[j]) continue;
            d[j] = d[t] + 1;
            st[j] = true;
            q.push(j);
        }
    }
    return -1;
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i = 0,a,b; i < m; i++){
        cin >> a >> b;
        add(a,b);
    }
    cout << bfs() << endl;
    return 0;
}