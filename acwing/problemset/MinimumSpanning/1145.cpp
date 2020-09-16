#include <bits/stdc++.h>
using namespace std;
const int N = 2020,M = 1e4 + 10;
typedef pair<int,pair<int,int>> PIII;
PIII edges[M];
int p[N];
int find(int x)
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
int n,m;
int res;
int cnt;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 0,a,b,c,x; i < m; i++){
        scanf("%d%d%d%d",&x,&a,&b,&c);
        if(x==1){
            a = find(a),b = find(b);
            res += c;
            p[a] = b;
        }else{
            edges[cnt++] = {c,{a,b}};
        }
    }
    sort(edges,edges+cnt);
    for(int i = 0; i < cnt; i++){
        auto t = edges[i];
        int a = t.second.first,b = t.second.second,c = t.first;
        a = find(a),b = find(b);
        if(a!=b){
            res += c;
            p[a] = b;
        }
    }
    cout << res << endl;
}