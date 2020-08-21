#include <bits/stdc++.h>
using namespace std;
#define REP(n) for(int i=0;i<n;i++)
const int N = 10;
int path[N];
bool st[N];
int n;
void dfs(int u)
{
  if(u==n)
  {
    REP(n) cout << path[i] << " ";
    cout << endl;
    return;
  }
  for(int i = 1; i <= n; i++)
  {
    if(!st[i]){
      st[i] = true;
      path[u] = i;
      dfs(u+1);
      st[i] = false;
      path[u] = 0;
    }
  }
}
int main()
{
  cin >> n;
  dfs(0);
}