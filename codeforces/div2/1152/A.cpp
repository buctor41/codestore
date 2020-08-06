#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int odd1 = 0, odd2 = 0,even1 = 0,even2 = 0;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        if(t%2==0) even1++;
        else odd1++;
    }
    for(int i = 1; i <= m; i++){
        int t;
        cin >> t;
        if(t%2==0) even2++;
        else odd2++;
    }
    int res = min(odd1,even2) + min(odd2,even1);
    cout << res << endl;
}