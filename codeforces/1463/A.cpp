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

int t,a,b,c;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        int sum = a + b + c;
        a = min(a,b);
        a = min(a,c);
        if(sum % 9 == 0){
            int t = sum / 9;
            if(a >= t) puts("YES");
            else puts("NO");
        }else puts("NO");
    }
}
