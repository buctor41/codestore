//https://www.acwing.com/problem/content/805/
#include <iostream>
#include <algorithm>
#include <vector>

#define PII pair<int,int>

using namespace std;

vector<PII> segs;
vector<PII> res;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        int l,r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    sort(arr.begin(),arr.end());
    int st = -2e9,ed = -2e9;
    for(auto seg: segs)
    {
        int l = seg.first,r = seg.second;
        if(l > ed){
            res.push_back({st,ed});
            st = l,ed = r;
        }else{
            ed = max(ed,r);
        }
    }
    if(ed!=-2e9) res.push_back({st,ed});
    cout << res.size() - 1 << endl;
}