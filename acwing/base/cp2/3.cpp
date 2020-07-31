//https://www.acwing.com/problem/content/830/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int stk[N],tt = 0;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        int x;
        cin >> s;
        if(s=="push"){
            cin >> x;
            stk[++tt] = x;
        }else if(s=="pop"){
            tt--;
        }else if(s=="empty"){
            if(tt==0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }else if(s=="query"){
            cout << stk[tt] << endl;
        }
    }
    return 0;
}