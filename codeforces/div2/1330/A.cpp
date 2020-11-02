#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[2*N];
int t;
int n,x;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&x);
        memset(a,0,sizeof a);
        for(int i = 0,c; i < n; i++){
            scanf("%d",&c);
            a[c] = 1;
        }
        int res = 1;
        for(int i = 0; i < x;i++){
            if(a[res]==1){
                res++;
                i--;
            }else{
                a[res]=1;
                res++;
            }
        }
        while(a[res]==1) res++;
        res--;
        cout << res <<endl;
    }
    return 0;
}
