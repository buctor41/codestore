#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
int a[N],s[N],n;
int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 2; i <= n; i++) s[i] = a[i] - a[i-1];
  ll v = 0,c = 0;
  for(int i = 2; i <= n; i++)
  {
    if(s[i] > 0) v += s[i];
    else c -= s[i];
  }
  cout << max(v,c) << endl;
  cout << abs(v-c)+1 << endl;
  return 0;
}