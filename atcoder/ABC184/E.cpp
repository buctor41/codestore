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

const int N = 2010;
char g[N][N];
int st[N*N];

set<int> dic[26];
int H,W;
signed main()
{
    fastio;
    memset(st,-1,sizeof(st));
    cin >> H >> W;
    int Start,End;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> g[i][j];
            int t = i * W + j;
            if(g[i][j]=='#') continue;
            if(g[i][j]=='.') continue;
            if(g[i][j]=='S'){
                Start = t;
                continue;
            }
            if(g[i][j]=='G'){
                End = t;
                continue;
            }
            if(g[i][j] >= 'a' && g[i][j] <='z'){
                dic[g[i][j]-'a'].insert(t);
            }

        }
    }
    queue<int> q;
    q.push(Start);
    st[Start] = 0;
    while(q.size()){
        int t = q.front();
        q.pop();
        if(t==End) break;
        int a = t / W,b = t % W,c = st[t];
        for(int i = 0; i < 4; i++){
            int x = a + dx[i],y = b + dy[i],z = x * W + y;
            if(x >= 0 && x < H && y >= 0 && y < W){
                if(g[x][y]=='#') continue;
                if(g[x][y]=='.' && st[z]==-1){
                    st[z] = c + 1;
                    q.push(z);
                    continue;
                }
                if(g[x][y] >= 'a' && g[x][y] <= 'z' && st[z]==-1){
                    st[z] = c + 1;
                    q.push(z);
                    dic[g[x][y]-'a'].erase(z);
                    continue;
                }
                if(g[x][y]=='G' && st[z]==-1){
                    st[z] = c + 1;
                    q.push(z);
                }
            }
        }
        if(g[a][b] >= 'a' && g[a][b] <= 'z'){
            for(auto z:dic[g[a][b]-'a']){
                if(st[z]==-1){
                    st[z] = c + 1;
                    q.push(z);
                    dic[g[a][b]-'a'].erase(z);
                }else{
                    dic[g[a][b]-'a'].erase(z);
                }
            }
        }
    }
    cout << st[End] <<endl;
}
