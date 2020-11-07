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

int t,p,q;
int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        cin >> p >> q;
        if(p%q){
            cout << p << endl;
            continue;
        }
        vector<pii> vec;
        for(int i = 2; i <= q / i; i++){
            int cnt = 0;
            while(q%i==0){
                q /= i;
                cnt++;
            }
            if(cnt) vec.pb({i,cnt});
        }
        if(q > 1) vec.pb({q,1});
        int ans = 1;
        for(auto X:vec){
            int a = X.F,b = X.S;
            int v = p;
            while(v%a==0) v/=a;
            for(int i = 0; i < b - 1; i++) v*=a;
            ans = max(ans,v);
        }
        cout << ans << endl;
    }
    return 0;
}
