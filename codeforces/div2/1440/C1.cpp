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
int a[N][N];
int t,n,m;
signed main()
{
    fastio;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < m; j++){
                a[i][j] = s[j] - '0';
            }
        }
        vector<vector<int> > ops;
        ops.reserve(3*n*m);
        for(int i = n - 1; i >= 2; i--){
            for(int j = m -1; j >= 0; j--){
                if(a[i][j]){
                    ops.pb({i,j,i-1,j,i-1,j?j-1:j+1});
                    a[i][j] ^= 1;
                    a[i-1][j] ^= 1;
                    a[i-1][j?j-1:j+1] ^= 1;
                }
            }
        }
        for(int j = m - 1; j >= 2; j--){
            if(a[0][j] && a[1][j]){
                ops.pb({0,j,1,j,0,j-1});
                a[0][j] ^= 1;
                a[1][j] ^= 1;
                a[0][j-1] ^= 1;
            }else if(a[0][j]){
                ops.pb({0,j,0,j-1,1,j-1});
                a[0][j] ^= 1;
                a[1][j-1] ^= 1;
                a[0][j-1] ^= 1;
            }else if(a[1][j]){
                ops.pb({1,j,1,j-1,0,j-1});
                a[1][j] ^= 1;
                a[0][j-1] ^= 1;
                a[1][j-1] ^= 1;
            }else{
                //none
            }
        }

/*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << a[i][j];
            cout << endl;
        }
        cout <<endl;
        */
        auto change = [&](int x1, int y1, int x2, int y2, int x3, int y3) {
            ops.pb({x1,y1,x2,y2,x3,y3});
            a[x1][y1] ^= 1;
            a[x2][y2] ^= 1;
            a[x3][y3] ^= 1;
        };
        if(a[1][1]==1){
            change(1,1,0,1,1,0);
        }
        if(a[0][0]+a[0][1]+a[1][0]==3){
            change(0,0,0,1,1,0);
        }
        if(a[0][0]+a[0][1]==2){
            change(0,1,1,0,1,1);
            change(0,0,1,0,1,1);
        }else if(a[0][0]+a[1][0]==2){
            change(0,1,1,0,1,1);
            change(0,0,0,1,1,1);
        }else if(a[1][0]+a[0][1]==2){
            change(0,0,0,1,1,1);
            change(0,1,1,0,1,1);
        }else if(a[0][0]){
            change(0,0,0,1,1,0);
            change(0,0,0,1,1,1);
            change(0,1,1,0,1,1);
        }else if(a[0][1]){
            change(0,0,0,1,1,0);
            change(0,1,1,0,1,1);
            change(0,0,1,0,1,1);
        }else if(a[1][0]){
            change(0,0,0,1,1,0);
            change(0,1,1,0,1,1);
            change(0,0,1,0,1,1);
        }
        cout << ops.size() << endl;
        for(auto &op:ops){
            for(int i = 0 ; i < op.size(); i++){
                cout << op[i]+1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
