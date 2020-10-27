#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int ct = 0;
        for(int i = 0,a;i < n; i++){
            cin >> a;
            ct += a;
        }
        if(ct==m){
            puts("YES");
        }else{
            puts("NO");
        }
    }
}