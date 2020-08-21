#include <bits/stdc++.h>
using namespace std;
#define REP(n) for(int i = 0; i < n; i++)
const int N = 1e5 + 10;
int p[N],cnt[N];
int n,m;
void init()
{
  REP(N){
    p[i] = i;
  }
  for(int i = 0; i < N; i++) cnt[i] = 1;
}
int find(int x)
{
  if(p[x]!=x) p[x] = find(p[x]);
  return p[x];
}
int main()
{
  init();
  cin >> n >> m;
  REP(m){
    char op[2];
    int a,b;
    scanf("%s",op);
    if(op[0]=='C'){
      scanf("%d%d",&a,&b);
      a = find(a);
      b = find(b);
      if(a!=b){
        p[a] = b;
        cnt[b] += cnt[a];
      }
    }else{
      if(op[1]=='1'){
        scanf("%d%d",&a,&b);
        a = find(a);
        b = find(b);
        if(a==b) cout << "Yes" << endl;
        else cout << "No" << endl;
      }else{
        scanf("%d",&a);
        a = find(a);
        cout << cnt[a] << endl;
      }
    }
  }
  return 0;
}