#include <bits/stdc++.h>
#define REP(x,l,u) for(int x = l; x < u; x++)
using namespace std;
//状态存储:字符串
//状态转移:swap
//状态判断:哈希表
int bfs(string &state)
{
    string end = "12345678x";
    queue<string> q;
    unordered_map<string,int> d;
    d[state] = 0;
    q.push(state);
    int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
    while(q.size())
    {
        auto t = q.front();
        int v = d[t];
        q.pop();
        if(t==end) return v;
        int k = t.find('x');
        int x = k / 3,y = k % 3;
        REP(i,0,4){
            int a = x + dx[i],b = y + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3){
                swap(t[k],t[a*3+b]);
                if(d.count(t)==0){
                    q.push(t);
                    d[t] = v + 1;
                }
                swap(t[k],t[a*3+b]);
            }
        }
    }
    return -1;
}
int main()
{
    string state;
    REP(i,0,9){
        char c;
        cin >> c;
        state += c;
    }
    cout << bfs(state) << endl;
    return 0;
}