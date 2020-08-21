#include <bits/stdc++.h>
#define REP(x,l,u) for(int x = l;x < u; x++)
#define PII pair<int,int>
using namespace std;
const int N = 110;
int g[N][N],n,m,d[N][N];
int bfs()
{
  queue<PII> q;
  q.push({0,0});
  int dx[4] = {-1,0,1,0};
  int dy[4] = {0,1,0,-1};
  d[0][0] = 0;
  while(q.size())
  {
    auto t = q.front();
    q.pop();
    REP(i,0,4){
      int x = t.first + dx[i],y = t.second + dy[i];
      if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0&&d[x][y]==-1)
      {
        d[x][y] = d[t.first][t.second] + 1;
        q.push({x,y});
      }
    }
  }
  return d[n-1][m-1];
}
int main()
{
  cin >> n >> m;
  memset(d,-1,sizeof d);
  REP(i,0,n){
    REP(j,0,m){
      cin >> g[i][j];
    }
  }
  cout << bfs() << endl;
}