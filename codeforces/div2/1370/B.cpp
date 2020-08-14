#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> even,odd;
        vector<pair<int,int>> res;
        for(int i = 1; i <= 2*n;i++){
            int v;
            cin >> v;
            if(v%2==0) even.push_back(i);
            else odd.push_back(i);
        }
        for(int i = 0; i < even.size(); i++){
            if(i+1 < even.size()){
                res.push_back({even[i],even[i+1]});
                i++;
            }
        }
        for(int i = 0; i < odd.size(); i++){
            if(i+1 < odd.size()){
                res.push_back({odd[i],odd[i+1]});
                i++;
            }
        }
        sort(res.begin(),res.end());
        for(int i = 0; i < n - 1; i++){
            cout << res[i].first << " " << res[i].second << endl;
        }
    }
    return 0;
}