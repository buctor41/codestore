#include <bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 2*n; i < 4*n; i+=2) printf("%d ",i);
        puts("");
    }
    return 0;
}
