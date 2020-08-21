#include <bits/stdc++.h>
using namespace std;
const int N = 40040;
int p[N];
void init()
{
  for(int i = 0; i < N; i++)
  {
    p[i] = i;
  }
}
int find(int x)
{
  if(p[x]!=x) p[x] = find(p[x]);
  return p[x];
}
int main()
{
  init();
  int n,m;
  cin >> n >> m;
  bool flag = false;
  for(int i = 1; i <= m; i++)
  {
    int x,y;
    string s;
    cin >> x >> y >> s;
    if(s[0]=='D')
    {
      int v1 = (x-1) * n + y;
      int v2 = x * n + y;
      v1 = find(v1);
      v2 = find(v2);
      if(v1==v2){
        cout << i << endl;
        flag = true;
        break;
      }
      p[v1] = v2;
    }else{
      int v1 = (x-1)*n + y;
      int v2 = (x-1)*n + y + 1;
      v1 = find(v1);
      v2 = find(v2);
      if(v1==v2){
        cout << i << endl;
        flag = true;
        break;
      }
      p[v1] = v2;
    }
  }
  if(!flag) cout << "draw" << endl;
  return 0;
}