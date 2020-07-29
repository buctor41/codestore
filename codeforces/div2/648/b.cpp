#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,v,f1 = 0,f2 = 0;
        cin >> n;
        vector<int> maxn(n);
        for(int i = 0; i < n; i++) cin >> maxn[i];
        for(int i = 0; i < n; i++)
        {
            cin >> v;
            if(v==0) f1 = 1;
            else f2 = 1;
        }
        if(f1==1 && f2==1) cout << "Yes" << endl;
        else{
            bool flag = true;
            for(int i = 0; i < n - 1; i++)
            {
                if(maxn[i] > maxn[i+1]) flag = false;
            }
            if(flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}