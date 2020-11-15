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
const int N = 2e5 + 10;
int s[N],t[N],p[N];
int sum[N];
int n,k;
signed main()
{
    fastio;
    memset(sum,0,sizeof(sum));
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> s[i] >> t[i] >> p[i];
        sum[s[i]] += p[i];
        sum[t[i]] -= p[i];
    }
    int Max = 0;
    for(int i = 0; i < N; i++)
    {
        if(i)  sum[i]+=sum[i-1];
        Max = max(Max,sum[i]);
    }
    if(Max > k) puts("No");
    else puts("Yes");
    return 0;
}
