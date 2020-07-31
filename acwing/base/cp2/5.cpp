//https://www.acwing.com/problem/content/832/
//单调栈
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int stk[N],tt,n;
int a[N];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        while(tt > 0 && a[i] <= stk[tt]) tt--;
        //stk中只有小于a[i]的数
        if(tt==0) cout << "-1" << " ";
        else cout << stk[tt] << " ";
        stk[++tt] = a[i];
    }
    return 0;
}