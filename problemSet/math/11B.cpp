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

int x;
signed main()
{
    fastio;
    cin >> x;
    x = abs(x);
    int l = 1,r = 1e5 + 10;
    while(l < r){
        int mid = l + r >>1;
        if(mid * (mid + 1) >= 2 * x) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}
