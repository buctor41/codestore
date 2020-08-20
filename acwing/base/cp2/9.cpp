#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10,M = 31 * N;
int son[M][2],idx;
int a[N],n;
void insert(int x)
{
  int pos = 0;
  for(int i = 30; i >= 0; i--)
  {
    int v = (x >> i) & 1;
    if(!son[pos][v]) son[pos][v] = ++idx;
    pos = son[pos][v];
  }
}
int query(int x)
{
  int pos = 0,res = 0;
  for(int i = 30; i >= 0; i--)
  {
    int v = (x >> i) & 1;
    if(son[pos][!v])
    {
      res = res * 2 + !v;
      pos = son[pos][!v];
    }else{
      res = res * 2 + v;
      pos = son[pos][v];
    }
  }
  return res;
}
int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  int res = 0;
  for(int i = 0; i < n; i++)
  {
    insert(a[i]);
    int t = query(a[i]);
    res = max(res,t^a[i]);
  }
  cout << res << endl;
}