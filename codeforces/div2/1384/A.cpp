#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int t,n;
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    string pre = "";
    for(int i = 0; i < a[i]; i++){
        pre = pre + ('a' + i % 26);
    }
    cout << pre << endl;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        solve();
    }
}