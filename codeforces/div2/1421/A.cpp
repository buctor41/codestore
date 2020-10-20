#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int a,b;
        int x = 0;
        cin >> a >> b;
        int offset = 0;
        while(((a >> offset)> 0) || ((b >> offset)> 0)){
            int fa = (a >> offset) & 1;
            int fb = (b >> offset) & 1;
            if(fa==1 || fb==1){
                x += (fa << offset);
            }
            offset++;
        }
        int res = (x ^ a) + (x ^ b);
        cout << res << endl;
    }
    return 0;
}