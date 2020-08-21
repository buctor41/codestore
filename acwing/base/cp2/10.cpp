#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int p[N];
int find(int x)
{
  if(p[x]!=x) p[x] = find(p[x]);
  return p[x];
}
void init()
{
  for(int i = 0; i < N; i++) p[i] = i;
}
int main()
{
  int n,m;
  cin >> m>> n;
  init();
  while(n--)
  {
    int a,b;
    char op[2];
    scanf("%s",op);
    cin >> a >> b;
    a = find(a);
    b = find(b);
    if(op[0]=='M'){
      p[a] = b;
    }else{
      if(a==b) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}