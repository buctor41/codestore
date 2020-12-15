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
int t,n;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        cin >> s;
        int l = s.size();
        bool flag = false;
        if(l < 4){
            puts("NO");
            continue;
        }
        if(s.substr(0,4)=="2020" || (s[l-1]=='0' && s[l-2]=='2' && s[l-3]=='0' && s[l-4]=='2')) flag = true;
        if(s.substr(0,3)=="202" && s[l-1]=='0') flag = true;
        if(s.substr(0,2)=="20" && s[l-1]=='0' && s[l-2]=='2') flag = true;
        if(s[0]=='2' && s[l-1]=='0' && s[l-2]=='2' && s[l-3]=='0') flag = true; 
        if(flag) puts("YES");
        else puts("NO");
    }   
}