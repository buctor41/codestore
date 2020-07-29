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
const int N = 1e5 + 10;
ll a,b,p;
void solve()
{   
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> maxn;
    int bias = 0;
    if(s[0]=='B') bias = 1; //A:0 B:1
    maxn.pb(1);
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i]!=s[i-1]) maxn.pb(i+1);
    }
    int bk = maxn[maxn.size() - 1];
    if(bk!=n) maxn.pb(n);
    //预处理结束
    vector<ll> arr;
    for(int i = 0; i < maxn.size() - 1; i++)
    {
        int cur = i + bias;
        if(cur % 2 == 0) arr.pb(a);
        else arr.pb(b);
    }
    arr.pb(0);
    for(int i = arr.size() - 2; i >= 0; i--) arr[i] += arr[i+1];
    int res;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= p)
        {
            res = maxn[i];
            break;
        }
    }
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