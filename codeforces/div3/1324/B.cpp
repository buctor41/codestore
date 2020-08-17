#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define CYL cout << "YES" << endl;
#define CNL cout << "NO" << endl;
const int N = 5e3 + 50;
int a[N];
vector<int> q[N];
int t,n;
bool check(int n){
    for(int i = 1;i <= n; i++){
        if(q[i].size() >= 3) return true;
        if(q[i].size() == 2){
            if(q[i][0]+1!=q[i][1]) return true;
        }
    }
    return false;
}
int main()
{
    fastio;
    cin >> t;
    while(t--){
        memset(a,0,sizeof(int)*N);
        for(int i = 0; i < N; i++) q[i].clear();
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            q[a[i]].push_back(i);
        }
        bool flag = check(n);        
        if(flag){
            CYL;
        }else{
            CNL;
        }
    }
}