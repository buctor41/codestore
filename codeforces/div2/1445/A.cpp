#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N],b[N];
int st[N];
int t,n,x;
int main()
{
    scanf("%d",&t);
    while(t--){
        memset(st,0,sizeof st);
        scanf("%d%d",&n,&x);
        for(int i = 0; i < n; i++) scanf("%d",&a[i]);
        for(int i = 0; i < n; i++) scanf("%d",&b[i]);
        sort(b,b+n);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                if(!st[j] && (a[i]+b[j] <= x)){
                    st[j] = 1;
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==n) puts("Yes");
        else puts("No");
    }
    return 0;
}
