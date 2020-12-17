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

const int N = 2020;
int a[N],s[N];
int n,d,ans;
signed main()
{
    fastio;
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) s[i] = a[i] - a[i-1];
    for(int i = 1; i <= n; i++){
        if(s[i] <= 0){
            int v = abs(s[i]);
            int c = v / d + 1;
            ans += c;
            s[i] += (c * d);
            s[i+1] -= (c * d);
        }
    }
    cout << ans <<endl;
}
