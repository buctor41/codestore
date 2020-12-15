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
int t,n;
signed main()
{
    fastio;   
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> vec;
        for(int i = 1; i <= n; i++){
            int v = read();
            vec.pb(v);
        }
        sort(vec.begin(),vec.end());
        vector<pii> a;
        int cnt = 0,v;
        for(int i = 0; i < n; i++){
            if(i==0){
                v = vec[0];
                cnt++;
                continue;
            }
            if(vec[i]!=v){
                a.push_back({v,cnt});
                v = vec[i];
                cnt = 1;
                continue;
            }
            cnt++;
        }
        a.push_back({v,cnt});
        int ans = 0;
        n = a.size();
        for(int i = 0; i < a.size() - 1; i++){
            int v0 = a[i].F,c0 = a[i].S;
            int v1 = a[i+1].F,c1=a[i+1].S;
            int v2 = a[i+2].F,c2=a[i+2].S;
            if(v2-v0==2 && c0 >0 && c1 > 0 && c2 > 0){
                ans += (c0 * c1 * c2);
            }
            if(c0 >= 3) ans += (c0 * (c0 - 1) * (c0 - 2) / 6);
            if(v0+1 == v1){
                if(c0 == 1 && c1 >= 2){
                    ans += (c1 * (c1 - 1) / 2);
                }
                if(c0 == 2 && c1 >= 1){
                    ans += c1;
                    if(c1 >= 2){
                        ans += c1 * (c1 - 1);
                    }
                }
            }
            if(v0 + 2 == v2){
                if(c0 == 1 && c2 >= 2){
                    ans += (c2 * (c2 - 1) / 2);
                }
                if(c0 == 2 && c2 >= 1){
                    ans += c2;
                    if(c2 >= 2){
                        ans += c2 * (c2 - 1);
                    }
                }
            }
        }
        if(n == 1){
            int c = a[0].S;
            if(c >= 3) ans+=(c * (c-1) * (c-2) / 6);
        }else{
            int c1 = a[n-1].S,c2 = a[n-2].S;
            if(c1 >= 3) ans += (c1 * (c1-1) * (c2-2) / 6);
            if(c2 >= 3) ans += (c2 * (c2-1) * (c2-2) / 6);
        }
        cout << ans << endl;
    }
}