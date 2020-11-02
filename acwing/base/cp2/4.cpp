//https://www.acwing.com/problem/content/831/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int q[N],hh,tt;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    tt = -1;
    int t;
    cin >> t;
    while(t--){
        string s;
        int x;
        cin >> s;
        if(s=="push"){
            cin >> x;
            q[++tt] = x;
        }else if(s=="pop"){
            hh++;
        }else if(s=="empty"){
            if(hh<=tt) cout << "NO" << endl;
            else cout << "YES" << endl;
        }else{
            cout << q[hh] << endl;
        }
    }
    return 0;
}
