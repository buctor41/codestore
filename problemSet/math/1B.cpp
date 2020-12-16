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

int t;
bool check(string &s)
{
    if(s.size() >= 4 && s[0]=='R' && s[1]>='1' && s[1] <= '9' && s.find("C",2) != -1) return true;
    return false;
}
int n;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        n = s.size();
        string ans;
        if(check(s)){
            int r = 0,c = 0,cnt;
            int i = 1;
            while(s[i]!='C') r = r * 10 + s[i++] - '0';
            i++;
            while(i < n) c = c * 10 + s[i++] - '0';
            string res;
            while(c > 0)
            {
                if(c % 26 == 0){
                    c = c / 26 - 1;
                    res += 'Z';
                }else{
                    res += 'A' + (c % 26) - 1;
                    c = c / 26;
                }
            }
            reverse(res.begin(),res.end());
            ans = res + to_string(r);
        }else{
            int r = 0,c = 0,i = 0;
            while(s[i] >= 'A' && s[i] <= 'Z') c = c * 26 + s[i++] - 'A' + 1;
            while(i < n) r = r * 10 + s[i++] - '0';
            ans = 'R' + to_string(r) + 'C' + to_string(c);
        }
        cout << ans << endl;
    }
}
//R[digit]C[digit]
//RC
