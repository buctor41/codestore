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
const int N = 1010;
int n,k;
int primes[N],cnt;
bool st[N];
void get_primes(int n)
{
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}
signed main()
{
    fastio;
    cin >> n >> k;
    get_primes(n);
    int ans = 0;
    for(int i = 0; i + 1 < cnt; i++){
        int v = primes[i] + primes[i+1] + 1;
        if(v <= n && !st[v]) ans++;
    }
    if(ans >= k) puts("YES");
    else puts("NO");
}

