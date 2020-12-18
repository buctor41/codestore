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
int a[2*N];
int t,n;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= 2 * n; i++) a[i] = 0;
        for(int i = 1,v; i <= n; i++){
            cin >> v;
            a[v] = 1;
        }
        int les1 = 0,les2 = n;
        int cnt = 0;
        for(int i = 1; i <= 2 * n; i++){
            if(a[i]==0){
                cnt++;
            }else{
                if(cnt == 0) les1++;
                else cnt--;
            }
        }
        cnt = 0;
        for(int i = 2 * n; i >= 1; i--){
            if(a[i]==0) cnt++;
            else{
                if(cnt == 0) les2--;
                else{
                    if(cnt == 0) les2--;
                    else cnt--;
                }
            }
        }
        int ans = abs(les1 - les2) + 1;
        cout << ans << endl;
    }
}
