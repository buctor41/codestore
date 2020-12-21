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

int a,b,n;
signed main()
{
    fastio;
    cin >> a >> b >> n;
    int v;
    if(a == 0){
        if(b!=0){
            puts("No solution");
            return 0;
        }else{
           cout << 0 << endl;
           return 0;
        }
    }else{
        v = b / a;
    }
    if(b % a != 0){
        puts("No solution");
        return 0;
    }

    if(v < 0){
        if(n % 2 == 0){
            puts("No solution");
            return 0;
        }
        int l = -1001,r = -1;
        while(l < r){
            int mid = l + r >> 1;
            if(pow(mid,n) >= v) r = mid;
            else l = mid + 1;
        }
        int _v = pow(l,n);
        if(_v == v){
            cout << l << endl;
        }else{
            puts("No solution");
        }
        return 0;
    }
    int l = 0, r = 1001;
    while(l < r){
        int mid = l + r >>1;
        if(pow(mid,n) >= v) r = mid;
        else l = mid + 1;
    }
    int _v = pow(l,n);
    if(_v == v){
        cout << l << endl;
    }else puts("No solution");
}
