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
    int cnt = 0;
    for(int i = 2; i < x; i++){
        int v = x;
        while(v){
            cnt += (v % i);
            v /= i;
        }
    }
    int g = __gcd(cnt,x-2);
    cout << cnt / g << "/" << (x - 2) / g << endl;
}
