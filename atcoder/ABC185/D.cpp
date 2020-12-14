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
const int N = 2e5 + 10;
int a[N];
int n,m;
signed main()
{
    fastio;   
    cin >> n >> m;
    if(m==0){
        puts("1");
        return 0;
    }
    for(int i = 0; i < m; i++) cin >> a[i];
    sort(a,a+m);
    int width = 1e9 + 10;
    vector<int> vec;
    for(int i = 0; i < m; i++){
        if(i==m-1){
            if(a[i] < n) {
                width = min(width,n-a[i]);
                vec.pb(n-a[i]);
            }
        }
        if(i==0){
            if(a[i] > 1) {
                width = min(width,a[i]-1);
                vec.pb(a[i]-1);
            }
            continue;
        }
        int len = a[i] - a[i-1] - 1;
        if(len > 0){
            width = min(width,len);
            vec.pb(len);
        }
    }
    int ans = 0;
    for(int i = 0; i < vec.size(); i++){
        ans += vec[i] / width;
        if(vec[i] % width !=0) ans++;
    }
    cout << ans << endl;
}
