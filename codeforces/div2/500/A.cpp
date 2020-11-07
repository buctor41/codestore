#include <bits/stdc++.h>
using namespace std;
const int N = 4e4;
int a[N];
int st[N];
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1; i < n; i++) scanf("%d",&a[i]);
    queue<int> q;
    q.push(1);
    st[1] = 1;
    while(q.size()){
        auto t = q.front();
        q.pop();
        int v = t + a[t];
        if(!st[v]){
            st[v] = 1;
            q.push(v);
        }
    }
    if(st[k]) puts("YES");
    else puts("NO");
}
