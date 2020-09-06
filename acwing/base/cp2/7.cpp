#include <bits/stdc++.h>
using namespace std;
const int N =1e5 + 10;
int st[N],hh = -1;
int q[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q[i];
    for(int i = 0; i < n; i++)
    {
        while(hh > 0 && st[hh] >= q[i]) hh--;
        if(hh > 0)
        {
            cout << st[hh] << " ";
        }else{
            cout << "-1 ";
            st[++hh] = q[i];
        }
    }
    cout << endl;
    return 0;
}