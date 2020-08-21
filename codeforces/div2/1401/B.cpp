#include <bits/stdc++.h>
using namespace std;
#define REP(x,l,u) for(int x = l,x < u; x++)
#define ll long long
void des(ll &a,ll &b)
{
    ll t = min(a,b);
    a -= t;
    b -= t;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll x1,y1,z1,x2,y2,z2;
        scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&z1,&x2,&y2,&z2);
        ll res = 2 * min(z1,y2);
        des(z1,y2); //2 1
        des(z1,z2); //2 2
        des(y1,y2); //1 1
        des(y1,x2); //1 0
        des(x1,z2); //0 2
        ll v = min(y1,z2);
        res -= 2 * v;
        printf("%lld\n",res);
    }
}
