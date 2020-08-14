#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin >> n >> k;
    ll cnt = n / k;
    if(cnt%2==0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
