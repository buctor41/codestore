//https://www.acwing.com/problem/content/855/
//bellman_ford算法
//时间复杂度O(MN)
//主要用法:判断经过k条边能否到达某个点
#include <bits/stdc++.h>
using namespace std;
const int N = 550,M = 10050;
int dist[N],backup[N];
int a[M],b[M],w[M];
int n,m,k;
int bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= k; i++){
        memcpy(backup,dist,sizeof dist);
        for(int j = 1; j <= m; j++){
            int x = a[j],y = b[j],z = w[j];
            dist[y] = min(dist[y],backup[x] + z);      //松弛操作
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2) return -1;
    else return dist[n];
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d",&a[i],&b[i],&w[i]);
    }
    int t = bellman_ford();
    if(t==-1) puts("impossible");
    else cout << t << endl;
    return 0;
}