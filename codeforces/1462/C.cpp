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
int t,x;
int st[10] = {0,9,17,24,30,35,39,42,44,45};
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> x;
        if(x > 45){
            puts("-1");
            continue;
        }
        if(x <= 9){
            cout << x << endl;
            continue;
        }
        vector<int> res;
        for(int i = 2; i <= 9; i++){
            if(x <= st[i]){
                for(int j = 9; j > 10 - i; j--) res.push_back(j);
                x -= st[i-1];
                break;
            }
        }
        if(x > 0) res.push_back(x);
        reverse(res.begin(),res.end());
        for(auto v:res) cout << v;
        cout << endl;
    }   
    return 0;
}