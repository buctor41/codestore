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

int T,n;
const int N = 1e5 + 10;
int t[N],x[N];
bool check(int l,int r,int v){
    if( l <= r && v >= l && v <= r) return true;
    if( l > r && v >= r && v <= l) return true;
    return false;
}
signed main()
{
    fastio;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> t[i] >> x[i];
        }
        int ans = 0,pos = 0,tar = 0,dir = 0,rst = 0;
        for(int i = 1; i <= n; i++){
            if(i == n){
                if(rst == 0) ans++;
                else if(check(pos,tar,x[i])) ans++;
                continue;
            }
            if(rst == 0){
                rst = abs(x[i] - pos);
                dir = x[i] >= pos ? 1 : -1;
                int cur = t[i+1] - t[i];
                if(rst <= cur){
                    ans++;
                    pos = x[i];
                    rst = 0;
                }else{
                    rst -= cur;
                    pos = pos + cur * dir;
                    tar = x[i];
                }
                continue;
            }
            int cur = min(rst,t[i+1]-t[i]);
            int _pos = pos + cur * dir;
            if(check(pos,_pos,x[i])) ans++;
            rst -= cur;
            pos = _pos;
        }
        cout << ans <<endl;
    }
}
