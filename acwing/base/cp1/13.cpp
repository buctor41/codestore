//https://www.acwing.com/problem/content/799/
#include <iostream>
#include <algorithm>
using namespace std;
const int N  = 1e5 + 10;
int s[N],n,m;
void insert(int l,int r,int v)
{
    s[l] += v;
    s[r+1] -= v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1,t; i <= n; i++){
        cin >> t;
        insert(i,i,t);
    }
    while(m--)
    {
        int l,r,v;
        cin >> l >> r >> v;
        insert(l,r,v);
    }
    for(int i = 1; i <= n; i++){
        s[i] += s[i-1];
        cout << s[i] << " "; 
    }
    cout << endl;
}