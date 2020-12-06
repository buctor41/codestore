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
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


inline int read() {
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
        while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
int t;
const int N = 330;
char a[N][N];
int t,n;


int check(int x,int y){
    if(a[x][y]=='x' && a[x][y+1]=='x' && a[x][y+2]=='x' && a[x+1][y]=='x'&&a[x+1][y+1]=='x'&&a[x+1][y+2]=='x' && && a[x+2][y]=='x'&&a[x+2][y+1]=='x'&&a[x+2][y+2]=='x'){
        return 1;
    }
}
signed main()
{
    fastio;   
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                char c;
                cin >> c;
                a[i][j] = c;
            }
        }
        if(n==1){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    cout << a[i][j];
                }
                cout << endl;
            }
            cout << endl;
            continue;
        }else if(n==2){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    cout << a[i][j];
                }
                cout << endl;
            }
            cout << endl;
            continue;
        }
        for(int i = 1; i + 2 <= n; i++){
            for(int j = 1; j + 2 <= n; j++){
                if(check(i,j)==1){
                    a[x][y]
                }
            }
        }
    }
}