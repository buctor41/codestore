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
        int rst = 0,pos = 0,tar = 0,ans = 0;
        for(int i = 1; i <= n; i++){
            if(i == n){
                ans++;
                continue;
            }
            if(rst == 0){
                
            }
        }
    }
}
