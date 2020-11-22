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


signed main()
{
    int n,x;
    string s;
    cin >> n >> x >> s;
    for(int i = 0; i < n; i++){
        if(s[i]=='o'){
            x++;
        }else{
            if(x==0) continue;
            x--;
        }
    }   
    cout << x << endl;
}