//https://www.acwing.com/problem/content/804/
#include <iostream>
#include <algorithm>
#include <vector>

#define PII pair<int,int>
#define ft first
#define sd second
#define ll long long
#define pb push_back
#define ppb pop_back
using namespace std;
const int N = 3e5 + 10;

vector<int> alls;
vector<PII> adds,querys;
int s[N],n,m;
int find(int x){
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x,c;
        cin >> x >> c;
        adds.pb({x,c});
        
        alls.pb(x);
    }
    for(int i = 0; i < m; i++){
        int l,r;
        cin >> l >> r;
        querys.pb({l,r});
        
        alls.pb(l);
        alls.pb(r);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());       //去重
    for(auto item: adds){
        int idx = find(item.ft);
        s[idx] += item.sd;
    }
    for(int i = 1; i <= alls.size(); i++) s[i] += s[i-1];
    for(auto item:querys){
        int l = find(item.ft),r = find(item.sd);

        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}