#include <bits/stdc++.h>
using namespace std;
const int N = 6060;
//并查集维护
typedef pair<int,pair<int,int>> PIII;
int p[N],w[N],ct[N];
int find(int x)
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
PIII edges[N];
int n,cnt;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 1; i <= n; i++) p[i] = i;
        for(int i = 1; i <= n; i++) ct[i] = 1;
        for(int i = 1; i <= n; i++) w[i] = 0;
        cnt = n - 1;
        for(int i = 0,a,b,c; i < cnt; i++){
            scanf("%d%d%d",&a,&b,&c);
            edges[i] = {c,{a,b}};
        }
        int res = 0;
        sort(edges,edges+cnt);
        for(int i = 0; i < cnt; i++){
            auto t = edges[i];
            int a = t.second.first,b = t.second.second,c = t.first;
            a = find(a),b = find(b);
            if(a!=b){
                int v = max(c,max(w[a],w[b])) + 1;
                int num = ct[a] * ct[b] - 1;
                p[a] = b;
                w[b] = v - 1;
                ct[b] += ct[a];
                res += (num * v);
            }
        }
        cout << res << endl;
    }
    return 0;
}
