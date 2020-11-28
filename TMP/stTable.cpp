#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int logn = 21;
int f[maxn][logn+1],Logn[maxn+1];
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
void Pre()
{
    Logn[1] = 0;
    Logn[2] = 1;
    for(int i = 3; i < maxn; i++){
        Logn[i] = Logn[i/2] + 1;
    }
}
int main()
{
    int n = read(),m = read();
    for(int i = 1; i <= n; i++) f[i][0] = read();
    Pre();
    for(int j = 1; j <= logn; j++){
        for(int i = 1; i+(1<<j)-1 <= n; i++){
            f[i][j] = max(f[i][j-1],f[i + (1 << (j-1))][j-1]);
        }
    }
    for(int i = 1; i <= m; i++){
        int l = read(),r = read();
        int s = Logn[r-l+1];
        printf("%d\n",max(f[l][s],f[r-(1<<s) + 1][s]));
    }
    return 0;
}