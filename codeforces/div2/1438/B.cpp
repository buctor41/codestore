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
const int N = 1010;
int b[N];
int t,n;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0 ; i < n; i++) cin >> b[i];
        sort(b,b+n);
        bool flag = false;
        for(int i = 0; i < n - 1; i++){
            if(b[i]==b[i+1]) flag = true;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
}