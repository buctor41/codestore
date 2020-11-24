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

#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int N = 110;
int t,n,m;
int a[N][N];

signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < _sz(s); j++){
                a[i][j] = s[j] - '0';
            }
        }
        vector<vector<int>> res;
        auto change = [&](int x1,int y1,int x2,int y2,int x3,int y3){
            res.pb({x1,y1,x2,y2,x3,y3});
            a[x1][y1] ^= 1;
            a[x2][y2] ^= 1;
            a[x3][y3] ^= 1;
        };
        //1
        for(int i = n -1; i >= 2; i--){
            for(int j = m - 1; j >= 0; j--){
                if(a[i][j]){
                    if(j>0){
                        change(i,j,i-1,j,i-1,j-1);
                    }else{
                        change(i,j,i-1,j,i-1,j+1);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a[i][j];
            }
            cout << endl;
        }

        //2


        //3
    }   
}