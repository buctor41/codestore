#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


void add(vector<int> &vec)
{
    int c = 1;
    for(auto &v:vec){
        v = (v + c) % 2;
        if(v == 0) c = 1;
        else c = 0;
        if(c == 0) break;
    }
    if(c) vec.pb(1);
}
int cmp(vector<int> &vec,string &s)
{
    int n = _sz(vec),m = _sz(s);
    if(n < m) return 1;
    if(n > m) return -1;
    for(int i =  n - 1; i >= 0; i--){
        if(vec[i] > (s[i] - '0')) return -1;
        else if(vec[i] < (s[i] - '0')) return 1;
    }
    return 0;
}
signed main()
{
    fastio;
    string s;
    int ans = 0;
    cin >> s;
    reverse(s.begin(),s.end());
    vector<int> vec(1,1);
    while(1)
    {
        int t = cmp(vec,s);
        if(t==1 || t==0){
            ans++;
            add(vec);
        }else if(t == -1) break;
    }
    cout <<ans <<endl;
}


//0 1 10 11
