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
const int N = 1010;
int a[N*N];
int t,n,k;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ll cnt = n * k;
        for(int i = 1; i <= cnt; i++) cin >> a[i];
        int sz;
        if(n%2==0) sz = n / 2;
        else sz = n / 2 + 1;
        int sum = 0;
        int ret = n - sz;
        int i = cnt;
        while(k--){
            i -= ret;
            sum += a[i];
            i--;
        }
        cout << sum << endl;
    }
    return 0;
}