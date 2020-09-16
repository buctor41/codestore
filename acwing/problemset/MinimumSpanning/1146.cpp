#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int p[N];
int find(int x)
{
   if(x!=p[x]) p[x] = find(p[x]);
   return p[x];
}
int n,m;
int main()
{
   scanf("%d%d",&n,&m);
   int tol = n * m;
   int x1,y1,x2,y2;
   for(int i = 0; i < tol; i++) p[i] = i;
   while(cin >> x1 >> y1 >> x2 >> y2){
      int x = (x1-1) * n + y1 - 1;
      int y = (x2-1) * n + y2 - 1;
      x = find(x),y = find(y);
      if(x!=y){
         p[x] = y;
      }
    }
    int cost = 0;
    for(int j = 1; j <= m; j++){
        for(int i = 1; i < n; i++){
            int x = (i-1)*n + j - 1;
            int y = (i) * n + j - 1;
            x = find(x),y = find(y);
            if(x!=y){
                p[x] = y;
                cost++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m ;j++){
            int x = (i-1) * n + j - 1;
            int y = (i-1) * n + j;
            x = find(x),y = find(y);
            if(x!=y){
                p[x] = y;
                cost += 2;
            }
        }
    }
    cout << cost << endl;
    return 0;
}

