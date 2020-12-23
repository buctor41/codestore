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

int n;
signed main()
{
    fastio;
    cin >> n;
    bool flag = false;
    for(int i = 1; i <= 500; i++){
        if(i * (i + 1) == 2 * n) {
            flag = true;
            break;
        }
    }
    if(flag) puts("YES");
    else puts("NO");
}
