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
const int N = 110;
int a[N];
int t;
int n;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            a[i] = n - i + 1;
        }
        if(n%2==1){
            swap(a[1],a[n/2+1]);
        }
        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}  
