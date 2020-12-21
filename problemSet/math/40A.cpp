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

int x,y;
signed main()
{
    fastio;
    cin >> x >> y;
    int v = x * y;
    if(v == 0) puts("black");
    else if(v > 0){
        double dis = sqrt(x * x + y * y);
        int d = dis;
        if(d == dis){
            puts("black");
        }else{
            if(d % 2 == 0) puts("black");
            else puts("white");
        }
    }else{
        double dis = sqrt(x * x + y * y);
        int d = dis;
        if(d == dis) puts("black");
        else{
            if(d % 2 == 0) puts("white");
            else puts("black");
        }
    }
    return 0;
}
