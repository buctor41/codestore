//https://www.acwing.com/problem/content/description/842/
//拉链法模拟散列表
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int Mod = 13333;
int h[N],e[N],ne[N],idx;
void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
void insert(int v)
{
    int r = abs(v) % Mod;
    add(r,v);
}
int hfind(int v)
{
    int r = abs(v) % Mod;
    for(int i = h[r];i!=-1;i=ne[i]){
        if(e[i]==v) return 1;
    }
    return 0;
}
int main()
{
    int n;
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    while(n--){
        char op[2];
        int v;
        scanf("%s%d",op,&v);
        if(op[0]=='I'){
            insert(v);
        }else{
            if(hfind(v)==1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}