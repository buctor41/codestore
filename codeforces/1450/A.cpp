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
int t;
int sz[26];
int state[6] = {'b'-'a','u'-'a','g'-'a','y'-'a','r'-'a','t'-'a'};
signed main()
{
    fastio;   
    cin >> t;
    while(t--){
        string s;
        int n;
        cin >> n >> s;
        for(auto c:s) sz[c-'a']++;
        string ans;
        for(int i = 0; i < 6; i++){
            while(sz[state[i]]){
                ans += ('a'+state[i]);
                sz[state[i]]--;
            }
        }
        for(int i = 0; i < 26; i++){
            while(sz[i]){
                ans+=('a'+i);
                sz[i]--;
            }
        }
        cout << ans << endl;
    }
}