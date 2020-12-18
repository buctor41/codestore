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

const int N = 55;
int a[N],b[N];
int t,n;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int sum0 = 0,sum1 = 0;
        for(int i = 1; i <= n; i+=2) sum0 += a[i];
        for(int i = 2; i <= n; i+=2) sum1 += a[i];
        if(sum0 < sum1){
            for(int i = 1; i <= n; i++){
                if(i % 2 == 1) b[i] = 1;
                else b[i] = a[i];
            }
        }else{
            for(int i = 1; i <= n; i++){
                if(i % 2 == 0) b[i] = 1;
                else b[i] = a[i];
            }
        }
        for(int i = 1; i <= n; i++) cout << b[i] << " ";
        cout << endl;
    }
}
