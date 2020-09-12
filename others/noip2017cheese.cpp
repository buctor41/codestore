#include <bits/stdc++.h>
using namespace std;
const int N = 1010,M = 2e6 + 10;
int h[N],e[M],ne[M],idx;
void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
double x[N],y[N],z[N];
int n;
double hh,rr;
bool st[N];
//top: n + 2
//bottom: n + 1
bool distance(double x1,double y1,double z1,double x2,double y2,double z2){
    double dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
    if(dis <= 2 * rr) return true;
    return false;
}
void build()
{
    memset(h,-1,sizeof h);
    idx = 0;
    for(int i = 1; i <= n; i++){
        if(z[i]+rr >= hh) {
            add(n+2,i),add(i,n+2);
        }
        if(z[i]-rr <= 0){
            add(n+1,i),add(i,n+1);
        }
        for(int j = i + 1; j <= n; j++){
            if(distance(x[i],y[i],z[i],x[j],y[j],z[j])){
                add(i,j),add(j,i);
            }
        }
    }
}
bool bfs()
{
    memset(st,false,sizeof st);
    queue<int> q;
    st[n+1] = true;
    q.push(n+1);
    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int i = h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(!st[j]){
                st[j] = true;
                q.push(j);
            }
        }
    }
    return st[n+2];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%lf%lf",&n,&hh,&rr);
        for(int i = 1; i <= n; i++){
            scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
        }
        build();
        if(bfs()) puts("Yes");
        else puts("No");
    }
}