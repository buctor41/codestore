#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+7;
int a[N],t[N];
int gcd(int x,int y)
{
	if(y == 0)	return x;
	return gcd(y,x % y);
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
		int n;scanf("%d",&n);
		int p = 1e9+7;
		for(int i = 1;i <= n;++i)	scanf("%d",&a[i]),p = min(p,a[i]),t[i] = a[i];
		sort(t + 1,t + n + 1);
		int ok = 1;
		for(int i = 1;i <= n;++i)	
		{
			if(t[i] != a[i] && gcd(t[i],p) == 1)
			{
				ok = 0;
				break;
			}
		}	
		if(!ok)	puts("NO");
		else puts("YES");
    }
    return 0;
}