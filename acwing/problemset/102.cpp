#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,f;
int a[N];
double s[N];
bool check(double v){
  for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i] - v;
  double minVal = 0;
  for(int i = 0, j = f; j <= n;i++,j++){
    minVal = min(minVal,s[i]);
    if(s[j] >= minVal) return true;
  }
  return false;
}
int main()
{
  cin >> n >> f;
  for(int i = 1; i <= n; i++) cin >> a[i];
  double l = 1,r = 2000;
  while(r - l > 1e-8){
    double mid = (l + r) / 2;
    if(check(mid)) l = mid;
    else r = mid;
  }
  int res = (int)(r * 1000);
  cout << res << endl;
}