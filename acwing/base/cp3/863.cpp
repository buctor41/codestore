#include <bits/stdc++.h>
using namespace std;
const int N = 550,M = 1e5 + 10;
int h[N],e[M],ne[M],idx;
//匈牙利算法
void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
bool st[N];
int match[N];
int n1,n2,m;
bool find(int u)
{
    for(int i = h[u];i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j]==0 || find(match[j])){
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d%d",&n1,&n2,&m);
    memset(h,-1,sizeof h);
    for(int i = 0,a,b; i < m; i++){
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    int res = 0;
    for(int i = 1; i <= n1; i++)
    {
        memset(st,false,sizeof st);
        if(find(i)) res++;
    }
    cout << res << endl;
}