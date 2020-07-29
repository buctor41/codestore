#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,v;
    cin >> n;
    unordered_map<int,int> hash;
    unordered_map<int,int> table;
    for(int i = 0; i < n; i++)
    {
        cin >> v;
        hash[v] = i;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> v;
        int dis;
        if(hash[v] > i)
        {
            dis = hash[v] - i;   
        }else{
            dis = n - i + hash[v];
        }
        table[dis]++;
    }
    int res = 0;
    for(auto x:table) res = max(res,x.second);
    cout << res << endl; 
}