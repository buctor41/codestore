#include <bits/stdc++.h>
using namespace std;
#define REP(x,l,u) for(int x = l,x < u; x++)
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if(n>k){
            int a = n % 2;
            int b = k % 2;
            if(a==b) printf("0\n");
            else printf("1\n");
        }else{
            int res =  k - n;
            printf("%d\n",res);
        }
    }
}