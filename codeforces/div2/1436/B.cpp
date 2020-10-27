#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int g[N][N],t,n;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(g,0,sizeof g);
        for(int i = 0 ; i < n; i++) g[i][i] = 1;
        for(int i = 0; i < n; i++) g[i][n-i-1] = 1;
        int k = n / 2;
        if(n%2==1){
            g[k-1][k-1] = 1,g[k-1][k] = 1,g[k-1][k+1] = 1;
            g[k][k-1] = 1,g[k][k+1] = 1;
            g[k+1][k-1] = 1,g[k+1][k] = 1,g[k+1][k+1] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ",g[i][j]);
            }
            puts("");
        }
    }
}
