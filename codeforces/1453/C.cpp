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
const int N = 2020;
int n,t;
int g[N][N];
int cnt[10];
signed main()
{
    fastio;  
    cin >> t;
    while(t--){
        cin >> n;
        memset(cnt,0,sizeof(cnt));
        for(int i = 1; i <= n; i++){
            for(int j = 1,v; j <= n; j++){
                char c;
                cin >> c;
                v = c - '0';
                cnt[v]++;
                g[i][j] = v;
            }
        }
        vector<int> ans;
        for(int i = 0; i < 10; i++){
            if(cnt[i] < 2){
                ans.pb(0);
                continue;
            }
            int maxRow = 1,minRow = n,maxCol = 1,minCol = n;
            vector<pii> arr; 
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= n; k++){
                    if(g[j][k]==i){
                        maxRow = max(maxRow,k);
                        minRow = min(minRow,k);
                        maxCol = max(maxCol,j);
                        minCol = min(minCol,j);
                        arr.pb({j,k});
                    }
                }
            }
            int res = 0;
            for(auto &t:arr){
                int i = t.F,j = t.S;
                int c1 = max(abs(j-1),abs(n-j));
                int r1 = max(abs(i-minCol),abs(maxCol-i));
                int s1 = c1 * r1;
                int c2 = max(abs(j-minRow),abs(maxRow-j));
                int r2 = max(abs(i-1),abs(n-i));
                int s2 = c2 * r2;
                res = max(res,max(s1,s2));
            }
            ans.pb(res);
            arr.clear();
        }
        for(auto v:ans) cout << v << " ";
        cout << endl;
    } 
    return 0;
}