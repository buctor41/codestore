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


inline int read() {
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
        while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
const int N = 3030;
int a[N];
int n,t;
signed main()
{
    fastio;   
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        set<int> s,res;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += a[i];
            s.insert(cnt);
        }
        cnt = 0;
        for(int i = n; i >= 1; i--){
            cnt += a[i];
            if(s.find(cnt)!=s.end()){
                res.insert(cnt);
            }
        }
        int ans = n - 1;
        for(auto v:res){
            int cnt = 0,_v = 0,c = 0;
            bool flag = true;
            for(int i = 1; i <= n; i++){
                _v += a[i];
                c++;
                if(_v > v){
                    flag = false;
                    break;
                }else if(_v == v){
                    _v = 0;
                    cnt += (c-1);
                    c = 0;
                }
            }
            if(_v!=0) flag = false;
            if(flag){
                ans = min(cnt,ans);
            }
        }
        cout << ans << endl;
    }
}
