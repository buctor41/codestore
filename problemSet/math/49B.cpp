#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

string a,b;
signed main()
{
    fastio;
    cin >> a >> b;
    int base = 0;
    for(auto c:a) base = max(c-'0',base);
    for(auto c:b) base = max(c-'0',base);
    base++;
    int c = 0, n = a.size(),m = b.size(),i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0)
    {
        c = a[i] - '0' + b[j] - '0' + c;
        c /= base;
        i--;j--;
    }
    while(i >= 0){
        c += a[i] - '0';
        c /= base;
        i--;
    }
    while(j >= 0){
        c += b[j] - '0';
        c /= base;
        j--;
    }
    int ans = max(n,m);
    if(c) cout << ans + 1 << endl;
    else cout << ans << endl;
    return 0;
}
