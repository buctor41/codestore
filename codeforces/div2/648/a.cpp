
// Problem : A. Matrix Game
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int m,n,v,res1 = 0,res2 = 0;
    cin >> m >> n;
    vector<int> row(m,0);
    vector<int> column(n,0);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> v;
            if(v==1)
            {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    for(auto x:row)
    {
        if(x==0) res1++;
    }
    for(auto x:column)
    {
        if(x==0) res2++;
    }
    int res = min(res1,res2);
    if(res%2==0)
    {
        cout << "Vivek" << endl;
    }else{
        cout << "Ashish" << endl;
    }
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
}
