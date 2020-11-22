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

bool check(int r1,int c1,int r2,int c2){
    if(r1+c1==r2+c2) return true;
    if(r1-c1==r2-c2) return true;
    if(abs(r1-r2)+abs(c1-c2) <= 3) return true;
    return false;
}

signed main()
{
    fastio;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a==c && b == d){
        cout << 0 << endl;
        return 0;
    }
    if(check(a,b,c,d)){
        cout << 1 << endl;
        return 0;
    }

    int r1 = b - a,r2 = d - c;
    int c1 = a + b,c2 = c + d;
    int _r = abs(r1-r2);
    int _c = abs(c1-c2);
    if(_r%2==0 || _c%2==0){
        cout << 2 << endl;
    }else{
        if(_r<=5 || _c <= 5){
            cout << 2 << endl;
        }else{
            cout << 3 << endl;
        }
    }
    return 0;

}