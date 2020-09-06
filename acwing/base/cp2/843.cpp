//https://www.acwing.com/problem/content/843/
//字符串hash
//h[l,r] = h[r] - h[l-1] * k^(r-l+1)
//ULL:自动取模
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int k = 131;
typedef unsigned long long ULL;
ULL h[N];
int n,m;
char s[N];
ULL pk[N];
ULL get(int l,int r)
{
    return h[r] - h[l-1] * pk[r-l+1];
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    //预处理
    h[0] = 0;
    pk[0] = 1;
    for(int i = 1; i <= n; i++){
        h[i] = h[i-1] * k + s[i];
        pk[i] = pk[i-1] * k;
    }
    while(m--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(get(a,b)==get(c,d)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}