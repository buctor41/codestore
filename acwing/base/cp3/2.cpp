#include <bits/stdc++.h>
using namespace std;
#define REP(x,l,u) for(ll x = l; x < u; x++)

typedef long long ll;
const int N = 10;
char g[N][N];
int n;
int col[N],gl[2*N],ugl[2*N];
void dfs(int u)
{
  if(u==n)
  {
    REP(i,0,n){
      REP(j,0,n){
        cout << g[i][j];
      }
      cout << endl;
    }
    cout << endl;
    return;
  }
  //y = -x + b
  REP(i,0,n)
  {
    if(!col[i] && !gl[u+i] && !ugl[i-u+n]){
      col[i] = gl[u+i] = ugl[i-u+n] = true;
      g[u][i] = 'Q';
      dfs(u+1);
      col[i] = gl[u+i] = ugl[i-u+n] = false;
      g[u][i] = '.';
    }
  }
}
int main()
{
  cin >> n;
  REP(i,0,n){
    REP(j,0,n){
      g[i][j] = '.';
    }
  }
  dfs(0);
}