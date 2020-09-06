//https://www.acwing.com/problem/content/854/
//spfa
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N],e[N],ne[N],w[N],idx;
void add(int a,int b,int c)
{
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}
int dist[N];
bool st[N];
int cnt[N];
int n,m;
int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];i!=-1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return 1;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return 0;
}
int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    for(int i = 0,a,b,c; i < m; i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int t = spfa();
    if(t==1) puts("Yes");
    else puts("No");
    return 0;
}