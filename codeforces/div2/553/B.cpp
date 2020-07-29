#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 550;
int n,m;
int q[N][N];
int road[N];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> q[i][j];
        }
    }
    int ret;
    for(int i = 1; i <= n; i++){
        if(i==1){
            ret = q[i][1];
            road[i] = 1;
            continue;
        }
        road[i] = 1;
        ret ^= q[i][1];
    }
     int flag = 0;
    if(!ret){
        for(int i = 1; i <= n; i++){
            for(int j = 2; j <= m; j++){
                if(q[i][1]!=q[i][j]){
                    flag = 1;
                    road[i] = j;
                    break;
                }
            }
            if(flag) break;
        }
    }
    if(flag){
        cout << "TAK" << endl;
        for(int i = 1; i <= n; i++) cout << road[i] << " ";
        cout << endl;
    }else{
        cout << "NIE" << endl;
    }

}

//XOR性质 不同为1
//0 1 2 3 4 5 6 7 8 9 
//0 1
//x y