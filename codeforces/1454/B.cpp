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

const int N = 2e5 + 10;
int a[N];
int sz[N];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int t,n;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        memset(sz,0,sizeof(int)*(n+1));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sz[a[i]]++;
        }
        int res = -1,v = n+1;
        for(int i = 1; i <= n; i++){
            if(sz[a[i]] == 1 && a[i] < v){
                res = i,v = a[i];
            }
        }
        cout << res << endl;
    }
}