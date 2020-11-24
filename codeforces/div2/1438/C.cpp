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
const int N = 1010;
int t,n;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        set<int> s;
        s.clear();
        bool flag1 = false;
        for(int i = 0,v; i < n; i++){
            cin >> v;
            if(s.find(v)==s.end()){
                s.insert(v);
            }else{
                flag1 = true;
                break;
            }
        }
        if(flag1) puts("YES");
        else puts("NO");
    }
}