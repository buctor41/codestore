#include <bits/stdc++.h>
using namespace std;
const int N = 330,M = 8800;
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
void kruskal()
{
    for(int i =1; i <= n; i++) p[i] = i;
    sort(edges,edges+m);
    for(int i = 0; i < m ;i++){
        auto t = edges[i];
        int a = t.second.first,b = t.second.second,c = t.first;
        a = find(a),b = find(b);
        if(a!=b){
            p[a] = b;
            res = max(res,c);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0,a,b,c; i < m; i++){
        scanf("%d%d%d",&a,&b,&c);
        edges[i] = {c,{a,b}};
    }
    kruskal();
    cout << n -1 << " " << res << endl;
}