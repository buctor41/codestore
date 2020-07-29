#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pb push_back
#define pp pop_back
#define PII pair<int,int>
#define ft first
#define sd second
using namespace std;
void solve()
{
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    int s1 = x * b;
    int s2 = y * a;
    int s3 = (a - x - 1) * b;
    int s4 = (b - y - 1) * a;
    int res = max(s1,max(s2,max(s3,s4)));
    cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}