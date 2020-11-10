#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int ll
int H,W,N,M;
signed main()
{
    fastio;
    cin >> H >> W >> N >> M;
    int on[H][W],state[H][W];
    memset(on,0,sizeof(on));
    memset(state,0,sizeof(state));
    for(int i = 0,r,c; i < N; i++){
        cin >> r >> c;
        --r,--c;
        state[r][c] = 1;
    }

    for(int i = 0,r,c; i < M; i++){
        cin >> r >> c;
        --r,--c;
        state[r][c] = 2;
    }

    for(int i = 0; i < H; i++){
        int start = 0;
        bool lit = 0;
        for(int j = 0; j < W; j++){
            if(state[i][j]==1){
                while(start < j){
                    on[i][start] = 1;
                    ++start;
                }
                lit = 1;
            }else if(state[i][j]==2){
                start = j + 1;
                lit = 0;
            }
            if(lit && state[i][j]!=2) on[i][j] = 1;
        }
    }

    for(int i = 0; i < W; i++){
        int start = 0;
        bool lit = 0;
        for(int j = 0; j < H; j++){
            if(state[j][i]==1){
                while(start < j){
                    on[start][i] = 1;
                    ++start;
                }
                lit = 1;
            }else if(state[j][i]==2){
                start = j + 1;
                lit = 0;
            }
            if(lit && state[j][i]!=2) on[j][i] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(on[i][j]) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}