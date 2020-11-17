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

int t,n,c0,c1,h;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        int cnt0 = 0,cnt1 = 0;
        for(auto c:s){
            if(c=='0') cnt0++;
            else cnt1++;
        }
        int res;
        if(c0 + h < c1){
            res = cnt1 * h + n * c0;
        }else if(c1 + h < c0){
            res = cnt0 * h + n * c1;
        }else{
            res =cnt0 * c0 + cnt1 * c1;
        }
        cout << res << endl;
    }
}