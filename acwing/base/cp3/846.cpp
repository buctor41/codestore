#include <bits/stdc++.h>
using namespace std;
//tree
const int N = 1e5 + 10,M = 2 * N;
int h[N],e[M],ne[M],idx;
void add(int a,int b)
{
  e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
int res = N;
bool st[N];
int n;
int dfs(int u)
{
  st[u] = true;
  int size = 0,sum = 0;
  for(int i = h[u];i!=-1;i=ne[i])
  {
    int j = e[i];
    if(st[j]) continue;
    int t = dfs(j);
    size = max(size,t);
    sum += t;
  }
  size = max(size,n-sum-1);
  res = min(size,res);
  return sum + 1;
}
int main()
{
  cin >> n;
  memset(h,-1,sizeof(int)*N);
  for(int i = 0,a,b; i < n - 1; i++)
  {
    cin >> a >> b;
    add(a,b),add(b,a);
  }
  dfs(1);
  cout << res << endl;
  return 0;
}