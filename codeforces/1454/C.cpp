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

const int N = 2e5 + 10;
int a[N];
int st[N];
int t,n;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        memset(st,-1,sizeof(int)*(n+1));
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<int> b;
        int res = 2*n;
        for(int i = 1; i <= n;){
            int j = i + 1;
            while(j <= n && a[i]==a[j]) j++;
            b.pb({a[i]});
            i = j;
        }
        if(_sz(b)==1){
            cout << 0 << endl;
            continue;
        }
        for(int i = 0; i < _sz(b); i++){
            if(i==0){
                st[b[i]] = 2;
                continue;
            }
            if(i==_sz(b)-1){
                if(st[b[i]]==-1) st[b[i]] = 2;
                else st[b[i]]++;
                continue;
            }
            if(st[b[i]]==-1) st[b[i]] = 2;
            else st[b[i]]++;
        }
        // for(auto t:b){
        //     cout << t << " ";
        // }
        int r = _sz(b) - 1;
        if(st[b[0]] > 1) st[b[0]]--;
        if(st[b[r]] > 1) st[b[r]]--;
        for(int i =1 ; i <= n; i++){
            if(st[i]!=-1) res = min(res,st[i]);
        }
        cout << res << endl;
    }
}