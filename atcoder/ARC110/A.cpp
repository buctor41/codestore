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
int n;
signed main()
{
    fastio;
    cin >> n;
    if(n==2){
        cout << 3 <<endl;
        return 0;
    }else if(n==3){
        cout << 7 <<endl;
        return 0;
    }
    unordered_map<int,int> hash;
    hash[2] = 1;
    hash[3] = 1;
    for(int i = 4; i <= n; i++){
        int v = i;
        for(int j = 2; j <= v /j; j++){
            int cnt = 0;
            while(v%j==0){
                v /= j;
                cnt++;
            }
            hash[j] = max(hash[j],cnt);
        }
        if(v > 1){
            if(hash[v]==0) hash[v] = 1;
        }
    }
    int ans = 1;
    for(auto t:hash){
        for(int i = 1; i <= t.S; i++){
            ans *= t.F;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
