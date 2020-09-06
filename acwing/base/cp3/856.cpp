//https://www.acwing.com/problem/content/description/856/
//floyd
#include <bits/stdc++.h>
using namespace std;
const int N = 220;
int d[N][N];
int n,m,k;
const int INF = 1e9;
void floyd()
{
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i==j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for(int i = 0,a,b,c;i < m; i++){
        scanf("%d%d%d",&a,&b,&c);
        d[a][b] = min(d[a][b],c);
    }
    floyd();
    for(int i = 0,a,b;i < k; i++){
        scanf("%d%d",&a,&b);
        if(d[a][b] > INF / 2 ) puts("impossible");
        else cout << d[a][b] << endl;
    }
    return 0;
}