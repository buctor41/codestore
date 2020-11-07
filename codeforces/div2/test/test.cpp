#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int s[N];
int t,n,a;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&a);
        memset(s,0,sizeof s);
        s[0] = 1,s[1] = 1;
        for(int i = 1; i <= n; i++){
            int c = 0;
            for(int j = 1; j <= s[0];j++){
                //s[j]*i+c %10
                int v = s[j] * i + c;
                s[j] = v % 10;
                c = v / 10;
            }
            while(c){
                s[0]++;
                s[s[0]] = c % 10;
                c /= 10;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= s[0];i++){
            if(s[i]==a) cnt++;
        }
        printf("%d\n",cnt);
    }
}
