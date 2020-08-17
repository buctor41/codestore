#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e4 + 10;
ll q[N];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> q[i];
        }
        ll a = q[0],b = q[1],c = q[n-1];
        if(((a+b) > c) && ((a+c) > b) && ((b+c) > a)){
            cout << -1 << endl;
        }else cout << "1 2 " << n << endl;
    }
}