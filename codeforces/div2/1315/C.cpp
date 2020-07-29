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
const int N = 110;
int b[N];
int a[2*N];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> maxn;
    vector<int> res;
    for(int i = 1; i <= 2 * n; i++)
    {
        bool flag = true;
        for(int j = 1; j <= n; j++)
        {
            if(b[j]==i) flag = false;
        }
        if(flag) maxn.pb(i);
    }
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        int target = b[i];
        //找到大于b[i]的
        int l = 0,r = maxn.size() - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(maxn[mid] > target) r = mid;
            else l = mid + 1;
        }
        if(l < 0 || l >= maxn.size() || maxn[l] < target){
            flag = false;
            break;
        }
        res.pb(target);
        res.pb(maxn[l]);
        maxn.erase(maxn.begin()+l);
    }
    if(flag){
        for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    }else{
        cout << -1;
    }
    cout << endl;
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