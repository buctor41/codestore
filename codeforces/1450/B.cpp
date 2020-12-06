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
const int N = 110;
int t,k,n;
int x[N],y[N];
signed main()
{
    fastio;   
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
        bool flag = false;
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = 1; j <= n; j++){
                int dis = abs(x[i]-x[j]) + abs(y[i]-y[j]);
                if(dis <= k){
                    cnt++;
                }
            }
            if(cnt==n){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << 1 << endl;
        }else{
            cout << -1 << endl;
        }
    }
}