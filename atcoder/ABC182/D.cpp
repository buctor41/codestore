#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define int ll

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())
const int N = 2e5 + 20;
int dis[N][3];          //dis[i][0]: curSite   dis[i][1]: offset    dis[i][2]:maxleftoffset
int n;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    int res = 0;
    dis[0][0] = 0,dis[0][1] = 0,dis[0][2]=0;
    for(int i = 1,t; i <= n; i++){
        cin >> t;
        dis[i][1] = dis[i-1][1] + t;
        dis[i][0] = dis[i-1][0] + dis[i][1];
        if((dis[i-1][0]+dis[i-1][2]) < dis[i][0]){
            dis[i][2] = dis[i][1];
        }else{
            dis[i][2] = dis[i-1][2];
        }
        res = max(res,dis[i-1][0]+dis[i][2]);
    }
    cout << res << endl;
}