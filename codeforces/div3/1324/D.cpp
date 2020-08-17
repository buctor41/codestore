#include <bits/stdc++.h>
using namespace std;
//DEFINE
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define CYL cout << "YES" << endl;
#define CNL cout << "NO" << endl;
#define ll long long
//GLOBAL
const int N = 2e5 + 10;
int a[N],b[N];
int n;
int main()
{
    fastio;
    cin >> n;
    vector<ll> c,d;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        int t = a[i] - b[i];
        if(t <= 0) c.push_back(t);
        else d.push_back(t);
    }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    sort(d.begin(),d.end());
    // 1 2 ... n-1
    //n * (n-1) / 2
    ll t = d.size();
    ll cnt = (t * (t-1)) / 2;
    int i = 0,j = 0;
    while(i < c.size() && j < d.size()){
        if(c[i]+d[j] > 0){
            cnt += t - j;
            i++;
        }else{
            j++;
        }
    }
    cout << cnt << endl;
}
// -6 -1 0 3 5
// 0 -1 -6
// 3 5 
