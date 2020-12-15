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
const int N = 330;
int a[N],ans[N];
int n,t;
signed main()
{
    fastio;  
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int i = 1,j = 1, k = n;
        bool flag = true;
        while( j <= k){
            if(flag){
                ans[i] = a[j++];
            }else{
                ans[i] = a[k--];
            }
            i++;
            flag = !flag;
        }
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}