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
const int N = 1e10;
int n;
string s;
signed main()
{
    fastio;
    cin >> n >> s;
    int ans = 0;
    if(s.size()==1){
        if(s[0]=='0'){
            ans = N;
        }else{
            ans=2*N;
        }
        cout << ans <<endl;
        return 0;
    }else if(s.size()==2){
        if(s[0]=='1' && s[1]=='1'){
            ans = N;
        }else if(s[0]=='1' && s[1]=='0'){
            ans = N;
        }else if(s[0]=='0' && s[1]=='1'){
            ans = N - 1;
        }else{
            ans = 0;
        }
        cout <<ans <<endl;
        return 0;
    }
    bool flag = true;
    bool outset = 0;
    if(s[0]=='1'&&s[1]=='1'){
        outset = 0;
        int i = 0;
        for(i; i + 2 < n; i+=3){
            if(s[i]=='1' && s[i+1]=='1'&&s[i+2]=='0'){
                continue;
            }else{
                flag = false;
                break;
            }
        }
        if(i < n && s[i]!='1') flag = false;
        if(i+1 < n && s[i+1]!='1') flag = false;
        if(!flag){
            ans = 0;
        }else{
            int sz = n / 3;
            if(n%3!=0) sz++;
            ans = N - sz + 1;
        }
    }else if(s[0]=='1' && s[1]=='0'){
        outset = 1;
        int i;
        for(i = 0; i + 2 < n; i+=3){
            if(s[i]=='1' && s[i+1]=='0' && s[i+2]=='1'){
                continue;
            }else{
                flag = false;
                break;
            }
        }
        if(i < n && s[i]!='1') flag = false;
        if(i+1 <n && s[i+1]!='0') flag = false;
        if(!flag){
            ans = 0;
        }else{
            int cnt = n - 2;
            int sz = 1 + cnt / 3;
            if(cnt%3!=0) sz++;
            ans = N - sz + 1;
        }
    }else if(s[0]=='0' && s[1]=='1'){
        outset = 2;
        int i;
        for( i = 0; i + 2 < n; i+=3){
            if(s[i]=='0' &&s[i+1]=='1' && s[i+2]=='1'){
                continue;
            }else{
                flag = false;
                break;
            }
        }
        if(i < n && s[i]!='0') flag = false;
        if(i+1 < n && s[i+1]!='1') flag = false;
        if(!flag){
            ans = 0;
        }else{
            int cnt = n - 1;
            int sz = 1 + cnt / 3;
            if(cnt%3!=0) sz++;
            ans = N - sz + 1;
        }
    }else{
        ans = 0;
    }
    cout << ans <<endl;
}
