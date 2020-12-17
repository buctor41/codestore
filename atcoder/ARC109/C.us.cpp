#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define int ll

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int n,k;
string s;
int a[110];
signed main()
{
    fastio;
    cin >> n >> k >> s;
    for(int i = 0; i < n; i++){
        if(s[i]=='R'){
            a[i] = 0;
        }else if(s[i]=='P'){
            a[i] = 1;
        }else{
            a[i] = 2;
        }
    }

    if(a[0]==0){
        puts("S");
    }else if(a[0]==1){
        puts("P");
    }else{
        puts("S");
    }
}