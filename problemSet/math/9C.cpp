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

string s;
signed main()
{
    fastio;
    cin >> s;
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < s.size(); i++)
    {
        int sl = s.size() - i;
        if(i==0 && s[i] == '1'){
            ans += (pow(2,sl-1) - 1);
            continue;
        }
        if(i == 0 && s[i] == '2'){
            ans += (pow(2,sl) - 1);
            break;
        }
        if(s[i] >= '2'){
            ans += (pow(2,sl));
            if(i == n - 1) ans--;
            break;
        }
        if(s[i]=='1'){
            ans += (pow(2,sl) - 1);
        }
    }
    cout << ans << endl;
}
//0 1 10 11
