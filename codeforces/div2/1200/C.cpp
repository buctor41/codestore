#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define ll long long
#define CNE cout << "NO" << endl
#define CYE cout << "YES" << endl
ll n,m,k;
ll ans[3];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    ll GCD = __gcd(n,m);         //GCD:被分成了多少块
    ans[1] = n / GCD;
    ans[2] = m / GCD;            //
    while(k--){
        ll s1,s2,e1,e2;
        cin >> s1 >> s2 >> e1 >> e2;
        ll idx1 = (s2-1) / ans[s1];
        ll idx2 = (e2-1) / ans[e1];
        if(idx1==idx2) CYE;
        else CNE;
    }
}