#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int g[N][N];
int T;
int x,y,n,m;
int cnt;
void init()
{
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++) g[i][j] = 0;
  }
  cnt = 0;
}
void dfs(int u,int v,int step)
{
  if(step==m*n){
    cnt++;
    return;
  }
  int dx[8] = {-2,-2,-1,1,2,2 ,1,-1};
  int dy[8] = {-1, 1, 2,2,1,-1,-2,-2};
  for(int i = 0; i < 8; i++)
  {
    int nx = u + dx[i],ny = v + dy[i];
    if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny]==0)
    {
      g[nx][ny] = 1;
      dfs(nx,ny,step+1);
      g[nx][ny] = 0;
    }
  }
}
int main()
{
  cin >> T;
  while(T--)
  {
    init();
    cin >> n >> m >> x >> y;
    g[x][y] = 1;
    dfs(x,y,1);
    cout << cnt << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int g[N][N];
int res = 0;
int T,m,n;
void dfs(int u,int v,int step)
{
  if(step==m*n)
  {
    res++;
    return;
  }
  int dx[8] = {-2,-2,-1,1,2,2,1,-1};
  int dy[8] = {-1,1,2,2,1,-1,-2,-2};
  for(int i = 0; i < 8; i++)
  {
    int x = u + dx[i],y = v + dy[i];
    if(x >= 0 && x < n && y >= 0 && y < n && g[x][y]==0)
    {
      g[x][y] = 1;
      dfs(x,y,step+1);
      g[x][y] = 0;
    }
  }
}
int main()
{
  cin >> T;
  while(T--)
  {
    int x,y;
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        g[i][j] = 0;
      }
    }
    res = 0;
    g[x][y] = 1;
    dfs(x,y,1);
    cout << res << endl;
  }
}