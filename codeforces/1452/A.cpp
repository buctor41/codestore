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

int t,a,b;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int res = min(a,b) * 2;
        int ret = max(a,b) - min(a,b);
        if(ret > 0){
            res = res + ret * 2 - 1;
        }
        cout << res << endl;
    }
}