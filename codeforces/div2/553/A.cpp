// https://codeforces.com/contest/1151/problem/A
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 55;
int q[N][4];
char t[4] = {'A','C','T','G'};
int main()
{
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < s.size();i++){
        for(int j = 0; j < 4;j++){
            int v = (s[i]-t[j] +26) % 26;
            if(v>13) v = 26 - v;
            q[i][j] = v;
        }
    }
    int ans = 10000;
    for(int i = 0; i < s.size() - 3; i++){
        ans = min(ans,q[i][0]+q[i+1][1]+q[i+2][2]+q[i+3][3]);
    }
    cout << ans << endl;
}