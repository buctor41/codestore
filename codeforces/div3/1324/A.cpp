#include <bits/stdc++.h>
using namespace std;
const int N = 110;
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int a[N];
int n,t;
int main()
{
    fastio;
    cin >> t;
    while(t--){
        memset(a,0,sizeof(int)*N);
        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i] %= 2;
            cnt += a[i];
        }
        if(cnt==0 || cnt==n){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
    }
    return 0;
}