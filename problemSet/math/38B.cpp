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

int g[8][8];
int rc,rr,kc,kr;

int dirx[8] = {-1,-2,-2,-1,1,2,2,1};
int diry[8] = {-2,-1,1,2,2,1,-1,-2};
signed main()
{
    fastio;
    char s[2][3];
    cin >> s[0] >> s[1];
    rr = s[0][0] - 'a';rc = s[0][1] - '1';
    kr = s[1][0] - 'a',kc = s[1][1] - '1';
    g[rr][rc] = 1;
    for(int i = 0; i < 8; i++){
        g[rr][i] = 1;
        g[i][rc] = 1;
    }
    g[kr][kc] = true;
    for(int i = 0; i < 8; i++){
        int x = kr + dirx[i],y = kc + diry[i];
        if(x >= 0 && x < 8 && y >= 0 && y < 8) g[x][y] = 1;
    }
    int cnt = 64;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(!g[i][j]){
                for(int k = 0; k < 8; k++){
                    int x = i + dirx[k],y = j + diry[k];
                    if(x == kr && y == kc) g[i][j] = true;
                    if(x == rr && y == rc) g[i][j] = true;
                }
            }
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cnt -= g[i][j];
        }
    }
    cout << cnt << endl;
    return 0;
}
