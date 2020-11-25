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
int t,n,c;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
       cin >> c;
        n = c;
       vector<pair<ll,ll>> a;
       
       for(int i = 2; i <= n / i; i++){
    //       cout << i << endl;
           int cnt = 0;
           while(n%i==0){
               n /= i;
               cnt++;
           }
           if(cnt > 0) a.pb({i,cnt}); 
       }

       if(n > 1) a.pb({n,1});
       int v = 0,sz = 0;
       for(auto &x:a){
           int _v = x.F,_sz = x.S;
           if(_sz > sz){
               v = _v;
               sz = _sz;
           }
       } 
       cout << sz << endl;
       for(int i = 1; i < sz; i++) cout << v << " ";
       int ans = c / (pow(v,sz-1));
       cout << ans << endl;  
    }
}

