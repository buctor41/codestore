#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int w[N];
int d[2*N];
int st[N];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&w[i]);
    for(int i = 1; i <= m; i++) scanf("%d",&d[i]);
    int res = 0;
    for(int i = 1; i <= m; i++){
        memset(st,0,sizeof st);
        st[d[i]] = 1;
        for(int j = i + 1; j <= m; j++){
            if(d[i]==d[j]) break;
            if(st[d[j]]==0){
                res += w[d[i]];
                st[d[j]] = 1;
            }
        }
    }
    cout << res << endl;
}
