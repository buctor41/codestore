#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2020;
char str[N];
int a[N][N],s[N][N];
int n,k;
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        scanf("%s",str+1);
        for(int j = 1; j <= n; j++){
            a[i][j] = (str[i][j]=='W'?0:1);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++{
        int mn = n + 1,mx = 0;
        for(int j = 1; j <= n; j++){
            if(a[i][j]) mn = min(mn,j),mx=max(mx,j);
        }
        if(!mx){
            ++cnt;
            continue;
        }
        if(mx - mn + 1 > k ) continue;
        insert(i,mx,)                        

    }
}