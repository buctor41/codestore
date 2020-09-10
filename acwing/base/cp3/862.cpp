//！！！无向图
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//染色法
const int N = 1e5 + 10;
int h[N],e[2*N],ne[2*N],idx;
int color[N];  //0:未被染色 1:被染成1  2:被染成2
void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
int n,m;
bool dfs(int u,int c)
{
    color[u] = c;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j,3-c)) return false;
        }else if(color[j]==c) return false;
    }
    return true;
}
int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag = false;
                break;
            }
        }
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}