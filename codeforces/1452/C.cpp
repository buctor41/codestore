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

int t;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = _sz(s);
        int a = 0,b = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i]=='('){
                a++;
            }else if(s[i]=='['){
                b++;
            }else if(s[i]==')' && a > 0){
                a--;
                ans++;
            }else if(s[i]==']' && b > 0){
                b--;
                ans++;
            }
        }
        cout << ans << endl;
    }
}