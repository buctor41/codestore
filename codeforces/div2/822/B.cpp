// find a valid range 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define ll long long
#define pb push_back
#define pp pop_back
#define PII pair<int,int>
#define ft first
#define sd second
using namespace std;
vector<int> res;
vector<int> tmp;
int n,m;
string s,t;
void solve()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s >> t;
    for(int i = 0; i < n; i++) res.pb(i);
    for(int i = 0; i < m - n+ 1; i++)
    {
        tmp.clear();
        for(int j = 0; j < n; j++){
            if(s[j]!=t[i+j]){
                tmp.pb(j);
            }
        }
        if(tmp.size() < res.size()){
            res.clear();
            for(int j = 0; j < tmp.size(); j++) res.pb(tmp[j]);
        }
    }  
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) cout << res[i]+1 << " ";
    cout << endl;
}
int main()
{
    solve();
}
