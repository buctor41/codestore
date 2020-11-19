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

const int N = 1e5 + 10;
int a[N];
int n,t;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int Min = a[1],Max = a[1],cur = 0;
        for(int i = 1; i <= n; i++){
            Min = min(Min,a[i]);
            Max = max(Max,a[i]);
            cur += a[i];
        }
        int cnt = Max * (n-1);
        int res;
        if(cnt < cur){
            int ret = cur - cnt;
            ret = ret % (n-1);
            if(ret){
                res = n - 1 - ret;
            }else{
                res = 0;
            }
        }else{
            res = cnt - cur;
        } 
        cout << res << endl;
    }
}