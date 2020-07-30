#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int blocks[N];
int n,m,k,t;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) cin >> blocks[i];
        bool flag = true;
        for(int i = 1; i < n; i++){
            int goal = max(0,blocks[i+1]-k);
            int s = abs(blocks[i]-goal);
            if(blocks[i]>=goal) m += s;
            else  m -= s;
            if(m < 0)  {flag = false;break;}
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}