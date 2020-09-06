//https://www.acwing.com/problem/content/853/
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
int n,m;
int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    st[1] = true;
    queue<int> q;
    q.push(1);
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
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
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
    if(t==-1) puts("impossible");
    else cout << t << endl;
    return 0;
}